/* Queue_sll.c  Queue's sll implementation
    本案为单链表实现的队列，带有头结点 Front，指出队位置前驱，Rear指入队位置前驱；
    Front->Next == NULL 为新空队列（仅有头结点），此时 Rear == Front；
    本案，没有对队列长度作出限制，申请空间失败认为是 IsFull()；
usage:
#include "queue.h"

Queue Q;
Q = CreateQueue();

Enqueue( 1, Q );
Enqueue( 2, Q );
value = Front( Q ); // return 1;
Dequeue( Q ); // Queue remain 1 cell(value == 2)
value = FrontAndDequeue( Q ) // return 2, queue empty
printf("queue is %sempty.\n", IsEmpty( Q ) ? "":"NOT ");
DisposeQueue( Q ); // free all space.
*/

#include "queue.h"

struct NODE {
    ElementType Value;
    struct NODE *Next;
};

struct QueueRecord {
    struct NODE *Front; // where Dequeue（ 出队 ）
    struct NODE *Rear; // where Enqueue ( 入队 )
};

void FatalError(char *msg){
    fprintf(stdout, "FatalError:%s\n", msg);
    exit(EXIT_FAILURE);
}

int IsEmpty( Queue Q ) {
    return ( Q->Front->Next == NULL );
}

static struct NODE *NewNode( ElementType X ){
    struct NODE *New;
    New = malloc( sizeof( struct NODE ) );
    if( New != NULL ){
        New->Value = X;
        New->Next = NULL;
        return New;
    } else {
        FatalError("malloc failure: at NewNode()");
    }
}

int IsFull( Queue Q ) {
    struct NODE *tmp;
    tmp = malloc( sizeof( struct NODE ));
    if( tmp == NULL )
        return 1;
    else {
        free( tmp );
        return 0;
    }
}

Queue CreateQueue( void ) {
    Queue Q;
    struct NODE *New;
    Q = malloc( sizeof( struct QueueRecord));
    if( Q != NULL ){
        New = NewNode( 0 );
        if( New != NULL )
            Q->Front = Q->Rear = New;
        else {
            free( Q ); // node alloc failuer, free all and return;
            Q = NULL;
        }
    }
    return Q;
}

void DisposeQueue( Queue Q ) {
    MakeEmpty( Q );
    free( Q );
}

void MakeEmpty( Queue Q ) {
    while( !IsEmpty( Q ) )
        Dequeue( Q );
}

void Enqueue( ElementType X, Queue Q ) {
    struct NODE *New;


    New = NewNode( X );
    if( New != NULL ){
        Q->Rear->Next = New;
        Q->Rear = New;
    }
}

ElementType Front( Queue Q ) {
    if( !IsEmpty( Q ))
        return Q->Front->Next->Value;
    else
        FatalError("Error usage:queue IsEmpty() at Front()");
}

void Dequeue( Queue Q ) {
    struct NODE *tmpNodePtr;
    if( !IsEmpty( Q ) ){
        tmpNodePtr = Q->Front;
        Q->Front = Q->Front->Next;
        free( tmpNodePtr );
    } else
        FatalError("Error usage:queue IsEmpty() at Dqueue()");
}

ElementType FrontAndDequeue( Queue Q ) {
    ElementType tmpValue;
    if( !IsEmpty( Q )){
        tmpValue = Front( Q );
        Dequeue( Q );
        return tmpValue;
    } else
        FatalError("Error usage:queue IsEmpty() at FrontAndDequeue()");
}