/* queue_test.c
*/


#include <stdio.h>
#include <stdlib.h>


//#define __Array__
#include "queue.h"


void main(){
    ElementType value;
    int i;
    Queue Q;
#ifdef __Array__
    Q = CreateQueue( 10 );
#else
    Q = CreateQueue( );
#endif

    Enqueue( 1, Q );
    Enqueue( 2, Q );
    value = Front( Q ); // return 1;
    printf("Enqueue:%d\n", value);
    Dequeue( Q ); // Queue remain 1 cell(value == 2)
    value = FrontAndDequeue( Q ); // return 2, queue empty
    printf("Enqueue:%d\n", value);
    printf("queue is %sempty.\n", IsEmpty( Q ) ? "":"NOT ");
    
    MakeEmpty( Q );

    for( value = 1; value < 10; value++){
        Enqueue( value, Q );
#ifdef __Array__
        printf( "Enqueue #%d, Rear=%d\n", value, RearPos( Q ));
#endif
    }
    printf("queue is %sFull.\n", IsFull( Q ) ? "":"NOT ");

    for(i = 0; i < 100000; i++){
      for( value = 1; value < 8; value++){
           Dequeue( Q );
        }

        for( value = 1; value < 9; value++){
            Enqueue( value, Q );
#ifdef __Array__
        printf( "Enqueue #%d, Rear=%d\n", value, RearPos( Q ));
#endif
        }
    }
    printf("%d\n", i);
    for(i = 0; i<100; i++){
        printf("%d ", FrontAndDequeue( Q ));
    }
    printf("\n");
    printf("queue is %sFull.\n", IsFull( Q ) ? "":"NOT ");
    printf("queue is %sempty.\n", IsEmpty( Q ) ? "":"NOT ");

    DisposeQueue( Q ); // free all space
}