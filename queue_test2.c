/* queue_test2.c  muiltiple thread queue test�������� sll ʵ��
*/
#include <stdio.h>
#include <windows.h>
#include <time.h>

#include "queue.h"

CRITICAL_SECTION cs;//�����ٽ���ȫ�ֱ���
Queue Q; // ȫ�ֶ���

DWORD WINAPI EnQueue_Thread( LPVOID lpParam ){
    int n = (int)lpParam;

    for (int i = 0;i < 40 ;i++){// һ�����40�������������˳���
        //�����ٽ���
        EnterCriticalSection(&cs);
        
        // enqueue & print
        //while( IsFull( Q ) ) Sleep( 0 ); // �����ȴ� sll ģʽ�´˾���������壬Sleep(0)��ʾ����ʱ��Ƭ
        Enqueue( (i+1)*100+i, Q );
        printf("<t:1> EnQueue:[%d]\n", (i+1)*100+i );
        
        //�뿪�ٽ���
        LeaveCriticalSection(&cs);
        Sleep( (rand() % 10) * 5 ); // vs  Sleep
    }
    printf("Thread #%d(EnQueue) returned successfully\n", n);
    return 0;
}

DWORD WINAPI DeQueue_Thread( LPVOID lpParam ){ // ÿ���߳��������10���������˳���
    int n = (int)lpParam;
    DWORD dwWrite;

    for (int i = 0;i < 10 ;i++){
        //�����ٽ���
        EnterCriticalSection(&cs);
        
        // dequeue & print
        while( IsEmpty( Q ) ) Sleep( 0 ); // �ӿյȴ� Sleep(0) ��ʾ����ʱ��Ƭ
        printf("----------------------------------------<t:%d> DeQueue:[%d]\n",n,FrontAndDequeue( Q ));
       
        //�뿪�ٽ���
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
        { .tfun = EnQueue_Thread, .Note = "EnQueue_Thread" }, // 1 ���߳�Ϊ���
        { .tfun = DeQueue_Thread, .Note = "DeQueue_Thread" }, // 2,3,4 ���̣߳�Ϊ �����߳�
        { .tfun = DeQueue_Thread, .Note = "DeQueue_Thread" },
        { .tfun = DeQueue_Thread, .Note = "DeQueue_Thread" }
    };
    //��ʼ���ٽ���
    InitializeCriticalSection(&cs);
    
    srand((unsigned)time(NULL)); // ����α�������

    for (int i = 0; i < 4; i++)
    {
        hThread[i] = CreateThread(NULL, 0, ThreadArray[i].tfun, (LPVOID)(i + 1), 0, &ThreadID);
        printf("Thread #%d (%s) has been created successfully.\n", i + 1, ThreadArray[i].Note );
        Sleep( 100 ); // ��Ҫһ��ʼ, vs Sleep
    }
    //�ȴ����н��̽���
    WaitForMultipleObjects(4, hThread, TRUE, INFINITE);

    // ��ն��У�����ʾ���
    while( !IsEmpty( Q )){
    	printf("DeQueue: %d\n", FrontAndDequeue( Q ));
    }
    printf("queue is %sFull.\n", IsFull( Q ) ? "":"NOT ");
    printf("queue is %sempty.\n", IsEmpty( Q ) ? "":"NOT ");
    printf("save as GB, is ok to disp hanzi ��ã�\n");

    //ɾ���ٽ���
    DeleteCriticalSection(&cs);
    return 0;
}