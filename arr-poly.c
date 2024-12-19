/* arr-poly.c   polynomial use array
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxDegree 5000

typedef struct P{
	long CoeffArray[ MaxDegree + 1 ];
	int HighPower;
} * Polynomial;

int Max(int a, int b){
	return (a>b?a:b);
}

void ZeroPolynomial( Polynomial Poly ){
	int i;
	for( i=0; i <= MaxDegree; i++)
		Poly->CoeffArray[ i ] =0;
	Poly->HighPower = 0;
}

void AddPolynomial( const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum){
	int i;

	ZeroPolynomial( PolySum );
	PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);
	for( i = PolySum->HighPower; i >= 0; i-- )
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

void MultPolynomial( const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd){
	int i, j;

	ZeroPolynomial( PolyProd );
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
	if( PolyProd->HighPower > MaxDegree )
		printf( "exceeded arry size\n" );
	else
		for( i = 0; i <= Poly1->HighPower; i++)
			for( j = 0; j <= Poly2->HighPower; j++)
				PolyProd->CoeffArray[ i + j ] += Poly1->CoeffArray[ i ] * Poly2->CoeffArray[ j ];
}

void PrintPolynomial( char* FuncName, const Polynomial Poly){
	int i;

	printf("%s", FuncName);
	for( i = Poly->HighPower; i >= 0; i--){
		if( Poly->CoeffArray[i] != 0){ // 系数为0，不打印
			
			// 处理系数，1不显示
			if( i == Poly->HighPower ){ // 处理首位（系数）
				if( Poly->CoeffArray[i] < 0)  printf("-"); // 只有-号打印
				if( abs(Poly->CoeffArray[i]) != 1) printf("%d", abs(Poly->CoeffArray[i]) ); // +1 -1 不打印,符号打印过了，这里取abs
			} else { // 非首位(系数)
				if( abs(Poly->CoeffArray[i]) == 1 && i != 0) // 系数为+1 -1，1 不打印(但是末位要打印，因此&& i!=0)
					printf("%c", Poly->CoeffArray[i] > 0?'+':'-'); // 只打印符号
				else
					printf("%+d",Poly->CoeffArray[i]); // abs不是1，或者是末位，打印带符号数
			}
			// 处理次方，1 不显示 ^n, 0 不显示 X^n 	
			if(i != 0) { // 0, 无显示 
				if( i == 1 ) // 只有 X
					printf("X");
				else 
					printf("X^%d", i);
			}
		}
	}
	printf("\n");
}

int main(){
	Polynomial Poly1,Poly2,PolySum,PolyProd;
	Polynomial PolyR[21];

	Poly1 = malloc(sizeof(*Poly1));
	ZeroPolynomial(Poly1);
	Poly1->HighPower = 4;
	Poly1->CoeffArray[0] = -9;
	Poly1->CoeffArray[1] = 7;
	Poly1->CoeffArray[2] = -5;
	Poly1->CoeffArray[3] = 3;
	Poly1->CoeffArray[4] = -2;

	Poly2 = malloc(sizeof(struct P));
	ZeroPolynomial(Poly2);
	Poly2->HighPower = 12;
	Poly2->CoeffArray[0] = -1;
	Poly2->CoeffArray[1] = -2;
	Poly2->CoeffArray[2] = 4;
	Poly2->CoeffArray[3] = -6;
	Poly2->CoeffArray[6] = 8;
	Poly2->CoeffArray[8] = -10;
	Poly2->CoeffArray[12] = 1;
	
	PrintPolynomial( "F(X)=", Poly1 );
	PrintPolynomial( "G(X)=", Poly2 );

	PolySum = malloc(sizeof(struct P));
	AddPolynomial(Poly1, Poly2, PolySum);
	PolyProd = malloc(sizeof(struct P));
	MultPolynomial(Poly1, Poly2, PolyProd);

	PrintPolynomial( "F(X)+G(X)=", PolySum);
	PrintPolynomial( "F(X)*G(X)=", PolyProd);

	PolyR[0] = malloc(sizeof(struct P));
	MultPolynomial( Poly1, Poly1, PolyR[0]);
	for (int i = 1; i < 19; ++i)
	{
		PolyR[i] = malloc(sizeof(struct P));
		MultPolynomial( Poly1, PolyR[i-1], PolyR[i] );
	}
	PrintPolynomial( "F(X)^20 = ", PolyR[18] );

}
