/* Queue.h  sll & array implementation common interface (.h)
    if use array implementation, befor include queue.h, add "#define __Array__"
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef __Queue_H__
#define __Queue_H__

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

void FatalError(char *msg);

int IsEmpty( Queue Q );
int IsFull( Queue Q );

#ifdef __Array__
Queue CreateQueue( int MaxElements );
int RearPos( Queue Q );
int FrontPos( Queue Q );
#else
Queue CreateQueue( void );
#endif

void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
void Enqueue( ElementType X, Queue Q );
ElementType Front( Queue Q );
void Dequeue( Queue Q );
ElementType FrontAndDequeue( Queue Q );

#endif