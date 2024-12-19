/* pipei.c 从标准输入读取，判断括号是否匹配
*/
// 括号包括: () [] {}

#include "stack.h"

int topos( char c ){
    static char p[]="([{)]}";
    int i;
    for( i = 0; i < 6; i++)
        if( p[i] == c ) return (i + 1);
    return 0; // 不是括号
}

int main(){
    char c;
    int pos;
    Stack S;

    S = CreateStack(20);

    while ( (c = getchar()) != EOF ){
        if( (pos = topos( c )) != 0 ){
            putchar( c );
            if( pos <= 3 )  // ([{
                Push( pos, S );
            else // )]}
                if( !IsEmpty( S ) && (pos - Top( S )) == 3 )// 匹配
                    Pop( S );
                else // 不匹配
                    FatalError("ERROR: not match\n");
        }
    }
    printf("\n");
    // file over, if stack not empty, error!
    if( !IsEmpty( S ) ) FatalError("ERROR: EOF & not match");
    printf("Good: match \n");
}