/* list.c  single link list test
*/
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void FatalError(char *msg){
    fprintf(stdout, "FatalError:%s\n", msg);
    exit(EXIT_FAILURE);
}

List MakeEmpty( List L ){
    L = (List) malloc (sizeof(struct Node));
    L->Element = -1;
    L->Next = NULL;
    return L;
}

int IsEmpty( List L ){
    return L->Next == NULL;
}

int IsLast( Position P, List L){
    return P->Next == NULL;
}

void Delete( ElementType X, List L ){
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if( !IsLast(P,L)){
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free( TmpCell );
    }
}

Position Find( ElementType X, List L ){
    /*Position P;
    P = L->Next;
    while( P != NULL && P->Element != X)
        P = P->Next;
    return P; */ //原书是这样，我考虑直接用FindPrevious实现如下
    return FindPrevious(X, L)->Next;
}

Position FindPrevious( ElementType X, List L){
    // 查找X第一次出现Node的前驱节点，找不到则P停留在表尾；
    Position P;
    P = L;
    while( P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}

int printNode( Position P ){
    // for easy read, ptr 保留四位
    if( P != NULL)
        printf("Node(0x%04x): Data=%d, Next=(0x%04x)\n", (long)P % 0x10000, P->Element, (long)P->Next % 0x10000);
}

int printSll( List L ){
    while(L != NULL){
        printNode( L );
        L = L->Next;
    }
}

void Insert( ElementType X, List L, Position P){
    // X节点，插在P节点之后
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ));
    if( TmpCell == NULL)
        FatalError("out of space!");
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList( List L){
    // 删除表内节点，保留表头
    Position P;

    P = L->Next;
    L->Next = NULL; // 头不删，封闭
    while( P != NULL){
        L = P->Next;
        free(P);
        P = L;
    }
}