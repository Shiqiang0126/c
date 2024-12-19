/* Stack_test.c
*/

#include "stack.h"

int main(){
    Stack S1, S2;

    S1 = CreateStack(20);
    Push( 99, S1 );
    Push( 88, S1 );
    PrintStack( S1 );
    Pop( S1 );
    PrintStack( S1 );
    S2 = CreateStack(10);
    PrintStack( S2 );
    Push( 77, S2 );
    PrintStack( S2 );
}