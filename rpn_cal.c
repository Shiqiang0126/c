/* rpn_cal.c  
*/

#include <string.h>

#include "stack.h"

int IsOpt(char *Token){// return 0 for not oprator, return 1=+ 2=- 3=* 4=( 5=)
	
	if( strlen( Token ) == 1 ) 
		return( ( strcspn("+-*", Token ) + 1) % 4 );
	return 0;
} 

int IsOpr(char *Token){ // Oprands, number; return 0 for not a number;
	
	return ( strspn( Token, "-0123456789" ) == strlen( Token ) );
}

int main(){
	char BufLine[512];
	char RpnExpression[512];
	char * Token;
	int LineNumber = 0, TokenNumber;
	int i, res, a, b;
	char restxt[16];
 	Stack S;

    S = CreateStack(20);

	while( gets( BufLine ) != NULL){
		LineNumber++;
		TokenNumber = 0;
		strcpy( RpnExpression, BufLine );

		//printf("BufLine[%d]\"%s\"\n", LineNumber, BufLine);

		Token = strtok( BufLine, " \t");
		while ( Token != NULL ){ //  NULL for no more token(end of line)
			TokenNumber++;
			// printf(" - Token[%d]:<%s>\n", TokenNumber, Token );

			if( IsOpt( Token ) ){
				switch( Token[0] ){
				case('+'):
					Push( TopAndPop( S ) + TopAndPop( S ), S );
					break;
				case('-'):
					b = TopAndPop( S );
					a = TopAndPop( S );
					Push( a - b , S );
					break;				
				case('*'):
					Push( TopAndPop( S ) * TopAndPop( S ), S );
					break;
				default:
					printf("Line[%d]:", LineNumber);
					FatalError("Operator not support.");
				}
			} else if ( IsOpr( Token ) ){ // Op number
				Push( atoi( Token ), S );
			} else {
				printf("Line[%d]Token[%d]:<%s>", LineNumber, TokenNumber, Token);
				FatalError("Token error, Nither operator nor oprands.");
			}
			Token = strtok( NULL, " \t" ); // next token 
		} // All Token done.
		printf( "%s= %d\n", RpnExpression, Top( S ) );
	} // Next Line
}	