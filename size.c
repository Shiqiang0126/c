/* size.c */
#include <stdio.h>

int main(){
	char *ptr;
	char s[10]; //??(10??);
	int x, /*blah blah*/xy = 1;
	printf("xy = %d\n", xy);
	printf("sizeof(char)=%d\n", sizeof( char ));
	printf("sizeof(int)=%d\n", sizeof( int ));
	printf("sizeof(long int)=%d\n", sizeof( long int ));
	printf("sizeof(float)=%d\n", sizeof( float ));
	printf("sizeof(double)=%d\n", sizeof( double ));
	printf("sizeof(char *)=%d\n", sizeof( char* ));
	printf("sizeof(ptr)=%d\n", sizeof(ptr));
	printf("sizeof(s[10])=%d\n", sizeof(s));
	printf("sizeof(long long)=%d\n", sizeof(long long));
}