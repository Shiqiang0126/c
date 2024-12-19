/* stack.c imlementation of ADT stack
*/
#include "stack.h"

#define EmptyTOS (-1)
#define MinStackSize ( 5 )

struct StackRecord{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

void FatalError(char *msg){
    fprintf(stdout, "FatalError:%s\n", msg);
    exit(EXIT_FAILURE);
}

int IsEmpty( Stack S ){
    return ( S->TopOfStack == EmptyTOS );
}

int IsFull( Stack S){
    return ( S->TopOfStack == S->Capacity-1 );
}

Stack CreateStack( int MaxElements ){
    Stack S;
    if( MaxElements < MinStackSize ) MaxElements = MinStackSize;
    S = malloc( sizeof( struct StackRecord ) );
    if( S == NULL ) FatalError( "ERROR: CerateStack failure" );
    S->Array = malloc( sizeof( ElementType ) * MaxElements);
    if( S->Array == NULL) FatalError( "ERROR: CerateStack.Array failure");
    S->Capacity = MaxElements;
    MakeEmpty( S );
    return S;
}

void DisposeStack( Stack S ){
    if( S != NULL ){
        free( S->Array );
        free( S );
    }
}

void MakeEmpty( Stack S ){
    S->TopOfStack = EmptyTOS;
}

void Push( ElementType X, Stack S ){
    if( !IsFull( S ) )
        S->Array[ ++S->TopOfStack ] = X;
    else
        FatalError("ERROR: PUSH failure, Stack Full");
}

ElementType Top( Stack S ){
    if( S != NULL && !IsEmpty( S ))
        return S->Array[ S->TopOfStack ];
    FatalError("ERROR: TOP failure, Stack null or empty");
    return 0; // avoid compiler warning
}

void Pop( Stack S ){
    if( S != NULL && !IsEmpty( S ))
        S->TopOfStack--;
    else
        FatalError("ERROR: POP, Stack null or empty");
}

ElementType TopAndPop( Stack S ){
    ElementType tmp;

    tmp = Top( S );
    Pop( S );
    return tmp;
}

void PrintStack( Stack S){
    int i;
    printf("Stack[0x%04d]: ", (long)S % 0x10000 );
    printf("C=%d", S->Capacity );
    printf(", Top=%d", S->TopOfStack );
    if( S->TopOfStack != EmptyTOS ) printf(", Topdata=%d", Top( S ));
    printf("\n");
    printf("=======\n");
    for(i = S->TopOfStack; i >= 0; i-- ){
        printf("[%04d]: %d\n", i, S->Array[i]);
    }
    printf("\n");
}