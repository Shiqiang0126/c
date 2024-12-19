/* stack.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _STACK_H_

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

void FatalError(char *msg);
int IsEmpty( Stack S );
int IsFull( Stack S);
Stack CreateStack( int MaxElements );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );
ElementType TopAndPop( Stack S );
void PrintStack( Stack S);

#endif // STACK H