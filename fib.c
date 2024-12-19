/* fib.c fibonachi */
#include <stdio.h>
#include <string.h>

#define BMAX 10240
 
int adda(unsigned char x1[], unsigned char x2[], unsigned char x3[], int bits){
	// x3 = x1 + x2
	int i;
	unsigned char t, sig = 0;

	for (i = 0; i < bits; i++){
		t = x1[i] + x2[i] + sig;
		sig = t > 9 ? 1:0;
		x3[i] = t % 10;
	}
	return sig;// 最高位sig!=0 说明 overflow
}

int tos(unsigned char x[], char *s, int bits){
	int i;

	while (--bits != 0 && x[bits] == 0)
		;

	for (i = 0; i < bits+1; i++)
		s[i] = x[i] + '0';
	s[i] = '\0';

	strrev(s);
	return 0;
}

int main(){
	unsigned int n,i,j;
	unsigned char x[3][BMAX];
	char s[BMAX];

	printf("Pls input n=? "); scanf("%u", &n);

	if (n==1||n==2){
		printf("Fib(%u) = 1\n", n);
		return 0;
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < BMAX; j++)
			x[i][j] = 0;

	x[0][0] = 1; x[1][0]=1;

	for (i = 2; i < n; i++)
		if (adda ( x[(i-1)%3], x[(i-2)%3], x[i%3], BMAX ) != 0){
			// arg3 = arg1 + arg2; return 1 == overflow
			printf("Overflow!\n");
			return -1;
		} 
			
	tos (x[(i-1)%3], s, BMAX);
	printf("Fib(%u) = %s\n", n, s);
	return 0;
}