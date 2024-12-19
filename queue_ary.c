/* Queue_ary.c queue's array implementation


    本案为动态数组实现的队列，带有空白隔离节点 Rear，为即将入队位置，Front为出队位置；
    Next 为后继计算，数组末端会绕行；
    Next(Rear) == Front 队列满；
    Rear == Front 队列空；
    队列最大值在CreateQueue时确定，实际为可用为 size-1 (Rear 占用了一个空位置)


usage:
#define __Array__
#include "queue.h"


Queue Q;
Q = CreateQueue( queue_size );


Enqueue( 1, Q );
Enqueue( 2, Q );
value = Front( Q ); // return 1;
Dequeue( Q ); // Queue remain 1 cell(value == 2)
value = FrontAndDequeue( Q ) // return 2, queue empty
printf("queue is %sempty.\n", IsEmpty( Q ) ? "":"NOT ");
DisposeQueue( Q ); // free all space.


*/


#define __Array__
#include "queue.h"


// Dynamically Array method
#define MinQueueSize ( 10 )
#define MaxQueueSize ( 10000 )


struct QueueRecord {
    int Capacity;
    int Front; // where Dequeue（ 出队 ）
    int Rear; // where Enqueue ( 入队 )
    int Size; // I'll do NOT use it;
    ElementType *Value;
};


void FatalError(char *msg){
    fprintf(stdout, "FatalError: %s\n", msg);
    exit(EXIT_FAILURE);
}


static int Next( int Position, Queue Q ){
    if( ++Position == Q->Capacity )
        Position = 0;
    return Position;
}


int RearPos( Queue Q ){
    return Q->Rear;
}


int FrontPos( Queue Q ){
    return Q->Front;
}


int IsEmpty( Queue Q ) {
    return ( Q->Front == Q->Rear );
}


int IsFull( Queue Q ) {
    return( Next( Q->Rear, Q ) == Q->Front);
}


Queue CreateQueue( int MaxElements ) {
    Queue Q;


    if( MaxElements > MaxQueueSize || MaxElements < MinQueueSize ) MaxElements = MinQueueSize;
    Q = malloc( sizeof( struct QueueRecord ) );
    if( Q != NULL ){
        Q->Capacity = MaxElements;
        Q->Rear = Q->Front = 0;
        Q->Value = malloc( sizeof( ElementType ) * MaxElements );
    }
    if( Q != NULL && Q->Value != NULL)
        return Q;
    else
        return NULL;
}


void DisposeQueue( Queue Q ) {
    free( Q->Value );
    free( Q );
}


void MakeEmpty( Queue Q ) {
    Q->Rear = Q->Front = 0;
}


void Enqueue( ElementType X, Queue Q ) {    
    if ( !IsFull( Q ) ) {
        Q->Value[Q->Rear] = X;
        Q->Rear = Next( Q->Rear, Q );
    } else
        FatalError("queue IsFull() at Enqueue()");
}


ElementType Front( Queue Q ) {
    if( !IsEmpty( Q ))
        return Q->Value[Q->Front];
    else
        FatalError("queue IsEmpty() at Front()");
}


void Dequeue( Queue Q ) {
    if( !IsEmpty( Q ) )
        Q->Front = Next( Q->Front, Q );
    else
        FatalError("queue IsEmpty() at Dqueue()");
}


ElementType FrontAndDequeue( Queue Q ) {
    ElementType tmpValue;
    if( !IsEmpty( Q )){
        tmpValue = Front( Q );
        Dequeue( Q );
        return tmpValue;
    } else
        FatalError("queue IsEmpty() at FrontAndDequeue()");
}
