/* queue_test2.c  muiltiple thread queue test；适用于 sll 实现
*/
#include <stdio.h>
#include <windows.h>
#include <time.h>

#include "queue.h"

CRITICAL_SECTION cs;//定义临界区全局变量
Queue Q; // 全局队列

DWORD WINAPI EnQueue_Thread( LPVOID lpParam ){
    int n = (int)lpParam;

    for (int i = 0;i < 40 ;i++){// 一共入队40个数，结束就退出；
        //进入临界区
        EnterCriticalSection(&cs);
        
        // enqueue & print
        //while( IsFull( Q ) ) Sleep( 0 ); // 队满等待 sll 模式下此句基本无意义，Sleep(0)表示交出时间片
        Enqueue( (i+1)*100+i, Q );
        printf("<t:1> EnQueue:[%d]\n", (i+1)*100+i );
        
        //离开临界区
        LeaveCriticalSection(&cs);
        Sleep( (rand() % 10) * 5 ); // vs  Sleep
    }
    printf("Thread #%d(EnQueue) returned successfully\n", n);
    return 0;
}

DWORD WINAPI DeQueue_Thread( LPVOID lpParam ){ // 每个线程随机出队10个数，就退出；
    int n = (int)lpParam;
    DWORD dwWrite;

    for (int i = 0;i < 10 ;i++){
        //进入临界区
        EnterCriticalSection(&cs);
        
        // dequeue & print
        while( IsEmpty( Q ) ) Sleep( 0 ); // 队空等待 Sleep(0) 表示交出时间片
        printf("----------------------------------------<t:%d> DeQueue:[%d]\n",n,FrontAndDequeue( Q ));
       
        //离开临界区
        LeaveCriticalSection(&cs);
        Sleep( (rand() % 10) * 50 ); // vs Sleep
    }
    printf("Thread #%d(DeQueue) returned successfully\n", n);
    return 0;
}

typedef struct T{
    //HANDLE hThread;
    DWORD WINAPI (*tfun)();
    char Note[128];
} Ttype;

int main(){
	ElementType value;
    int i;
    Q = CreateQueue( );

    DWORD ThreadID;
    HANDLE hThread[4];
    Ttype ThreadArray[] = {
        { .tfun = EnQueue_Thread, .Note = "EnQueue_Thread" }, // 1 号线程为入队
        { .tfun = DeQueue_Thread, .Note = "DeQueue_Thread" }, // 2,3,4 号线程，为 出队线程
        { .tfun = DeQueue_Thread, .Note = "DeQueue_Thread" },
        { .tfun = DeQueue_Thread, .Note = "DeQueue_Thread" }
    };
    //初始化临界区
    InitializeCriticalSection(&cs);
    
    srand((unsigned)time(NULL)); // 打乱伪随机种子

    for (int i = 0; i < 4; i++)
    {
        hThread[i] = CreateThread(NULL, 0, ThreadArray[i].tfun, (LPVOID)(i + 1), 0, &ThreadID);
        printf("Thread #%d (%s) has been created successfully.\n", i + 1, ThreadArray[i].Note );
        Sleep( 100 ); // 不要一起开始, vs Sleep
    }
    //等待所有进程结束
    WaitForMultipleObjects(4, hThread, TRUE, INFINITE);

    // 清空队列，并显示结果
    while( !IsEmpty( Q )){
    	printf("DeQueue: %d\n", FrontAndDequeue( Q ));
    }
    printf("queue is %sFull.\n", IsFull( Q ) ? "":"NOT ");
    printf("queue is %sempty.\n", IsEmpty( Q ) ? "":"NOT ");
    printf("save as GB, is ok to disp hanzi 你好！\n");

    //删除临界区
    DeleteCriticalSection(&cs);
    return 0;
}