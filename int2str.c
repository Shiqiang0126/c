/* int2str.c */
#include <stdio.h>

void b2c(unsigned int value){
	unsigned int q; // 余数

	if ( (q = value / 10) !=0 ) b2c( q );
	putchar( value % 10 +'0');
}

int main(){
	unsigned int i;

	for (i=1000; i < 1599; i+=13){
		printf("%3d: ",i);
		b2c(i);
		printf("\n");
	}
}