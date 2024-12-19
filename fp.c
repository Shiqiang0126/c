/* fp.c function pointer test */
#include <stdio.h>

int p1(){
	printf("P1 routing here~\n");
	return 1;
}

int p2(){
	printf("P2 routing HERE!\n");
	return 2;
}

int (*f[2])() = {p1,p2};

int main(){

	int (*fp)() = p2;
	printf("Return %d\n",fp());
	fp = p1;
	printf("Return %d\n", (*fp)());
	printf("\n");

	f[0](); f[1](); printf("\n");

	f[0] = p2; f[1] = p1;
	f[0](); f[1]();
}