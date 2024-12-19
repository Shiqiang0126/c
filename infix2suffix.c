/* infix2suffix.c  use stack.c translat deal infix expression to suffix expression, then print to stdout
*/

#include <string.h>

#include "stack.h"


int IsOpt(char *Token){// return 0 for not oprator, return 1=+ 2=- 3=* 4=( 5=)
	char t[2]={Token[0], 0};
	return( (strcspn("+-*()", t) + 1) % 6 );
} 

int IsOpr(char *Token){ // Oprands, number; return 0 for not a number;
	
	return ( strspn( Token, "0123456789" ) == strlen( Token ) );
}

int main(){
	char BufLine[512];
	char * Token;
	char RpnExpression[512];
	int LineNumber = 0, TokenNumber;
	int i;
 	Stack S;

    S = CreateStack(20);

	while( gets( BufLine ) != NULL){
		LineNumber++;
		TokenNumber = 0;
		RpnExpression[0] = '\0';

		//printf("BufLine[%d]\"%s\"\n", LineNumber, BufLine);

		Token = strtok( BufLine, " \t");
		while ( Token != NULL ){ //  for no more token(end of line)
			TokenNumber++;
			
			//printf(" - Token[%d]:<%s>\n", TokenNumber, Token );

			if( IsOpt( Token ) ){
				switch (Token[0]){
				case ( '+' ):
					if( IsEmpty( S ) || Top( S ) == '(' ){
						Push( '+', S );
					} else {
						while( Top( S ) == '*' || Top( S ) == '-' || Top( S ) == '+' ){
							i = strlen(RpnExpression);
							RpnExpression[ i ] = TopAndPop( S );
							RpnExpression[ i + 1 ] = ' ';
							RpnExpression[ i + 2 ] = 0;
							if( IsEmpty( S ) || Top( S ) == '(' ) {
								Push( '+', S );
								break;
							}
						}
					}
					break;
				case ( '-' ):
					if( IsEmpty( S ) || Top( S ) == '(' ){
						Push( '-', S );
					} else {
						while( Top( S ) == '*' || Top( S ) == '-' || Top( S ) == '+' ){
							i = strlen(RpnExpression);
							RpnExpression[ i ] = TopAndPop( S );
							RpnExpression[ i + 1 ] = ' ';
							RpnExpression[ i + 2 ] = 0;
							if( IsEmpty( S ) || Top( S ) == '(' ) {
								Push( '-', S );
								break;
							}
						}
					}
					break;
				case ( '*' ):
					if( IsEmpty( S ) || Top( S ) == '-' || Top( S ) == '+' || Top( S ) == '(' ) {
						Push( '*', S );
					} else {
						while( Top( S ) == '*' ){
							i = strlen(RpnExpression);
							RpnExpression[ i ] = TopAndPop( S );
							RpnExpression[ i + 1 ] = ' ';
							RpnExpression[ i + 2 ] = 0;
							if( IsEmpty( S ) || Top( S ) != '*' ) {
								Push( '*', S );
								break;
							}
						}
					}
					break;
				case ( '(' ):
					if( 1 ) {
						Push( '(', S );
					} else {
						;
					}
					break;
				case ( ')' ):
					if( 0 ) {
						;
					} else {
						while( Top( S ) != '(' ){
							i = strlen(RpnExpression);
							RpnExpression[ i ] = TopAndPop( S );
							RpnExpression[ i + 1 ] = ' ';
							RpnExpression[ i + 2 ] = 0;
							if( Top( S ) == '(' ) {
								Pop( S );
								break;
							}
						}
					}
					break;
				}
			} else if ( IsOpr( Token ) ){ // Op number
				strcat( RpnExpression, Token);
				strcat( RpnExpression, " ");
				// printf("%s\n", RpnExpression );
			} else {
				printf("Line[%d]:", LineNumber);
				FatalError("Token error");
			}
			Token = strtok( NULL, " \t" ); // next token 
		}
		while( !IsEmpty( S ) ){
			i = strlen(RpnExpression);
			RpnExpression[ i ] = TopAndPop( S );
			RpnExpression[ i + 1 ] = ' ';
			RpnExpression[ i + 2 ] = 0;
		}
	printf( "%s\n", RpnExpression );
	}
	
}