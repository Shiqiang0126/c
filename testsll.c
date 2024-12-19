/* testsll.c  test list.h list.c
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(){
    List L;

    printf("New list and header\n");
    L = MakeEmpty( L );
    printNode( L );
    printf("Insert 88 77 66(befor77) 44(tail)\n");
    Insert( 88, L, L);
    Insert( 77, L, L->Next);
    Insert( 66, L, FindPrevious(77,L));// 插在77前驱之后（本身之前）
    Insert( 44, L, FindPrevious(99,L));// 99不存在，则插队尾之后
    printSll( L );
    printf("find & print node 66\n");
    printNode( Find( 66, L));
    printf("delete node 66\n");
    Delete( 66, L);
    printSll( L );
    printf("delete list node\n");
    DeleteList( L );
    printSll( L );

    printf("insert in order:\n"); //以下：将随机数有序插入链表
    srand((unsigned)time(NULL));
    int new_val, i;
    Position P = L;
    for(i = 0; i<10; i++){
        new_val = rand();
        for( P = L; P->Next != NULL && P->Next->Element < new_val; P = P->Next )
            ;
        Insert(new_val, L, P); // 或者末尾，或者合适位置
    }
    printSll( L );
    DeleteList( L );
}