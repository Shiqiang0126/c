/* bc.c  bit count */
#include <stdio.h>
#include <math.h>

int bc(unsigned v){
	int ones;

	for (ones = 0; v != 0; v = v >> 1)
		if(v%2 != 0) ones++;

	return ones;
}

void b2s(unsigned char v, char *s){
	unsigned int m = 0x100;

	while ( m >>= 1 )
		*s++ = v & m ? '1' : '0';
	*s = '\0';
}

void b2s2(unsigned long int v, int bits, char *s){

	while ( bits ) 
		*s++ = v & (1<<--bits) ? '1' : '0';
	*s = '\0';
}

int main(){
	unsigned int i = 0;
	unsigned char s1[256], s2[256]="";

	while ( i < 70 ){
		printf("%d, ", i);
		//b2s( (unsigned char)(i >> 8), s1 );
		//b2s( (unsigned char)(i << 8 >> 8), s2);
		b2s2 (i, 8, s1);
		printf("%s%sb, bc=%d\n", s1,s2, bc(i));
		i += 1;
	}
}