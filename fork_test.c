/* fork_test.c
*/
#include <stdio.h>
#include <windows.h>

HANDLE hFile;
CRITICAL_SECTION cs;//定义临界区全局变量
//线程函数：在文件中写入10000个hello
DWORD WINAPI Thread(LPVOID lpParam)
{
    int n = (int)lpParam;
    DWORD dwWrite;
    for (int i = 0;i < 10 ;i++)
    {
        //进入临界区
        EnterCriticalSection(&cs);
        char data[512];
        sprintf(data, "<t:%d> [%d] Hello\n", n, i);
        printf("%s", data);
        //写文件
        WriteFile(hFile, data, strlen(data), &dwWrite, NULL);
        //离开临界区
        LeaveCriticalSection(&cs);
    }
    printf("Thread #%d returned successfully\n", n);
    return 0;
}
int main()
{
    //char *filename = "hack.txt";
    //WCHAR name[20] = { 0 };
    //MultiByteToWideChar(CP_ACP, 0, filename, strlen(filename) + 1, name, sizeof(name) / sizeof(name[0]));
    //创建文件
    hFile = CreateFile(TEXT("hack.txt"), /*name,*/ GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("CreateFile error.\n");
        return 0;
    }
    DWORD ThreadID;
    HANDLE hThread[8];
    //初始化临界区
    InitializeCriticalSection(&cs);
    for (int i = 0;i < 8;i++)
    {
        //创建线程，并调用Thread写文件
        hThread[i] = CreateThread(NULL, 0, Thread, (LPVOID)(i + 1), 0, &ThreadID);
        printf("Thread #%d has been created successfully.\n", i + 1);
    }
    //等待所有进程结束
    WaitForMultipleObjects(8, hThread, TRUE, INFINITE);
    //删除临界区
    DeleteCriticalSection(&cs);
    //关闭文件句柄
    CloseHandle(hFile);
    return 0;
}