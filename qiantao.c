/* qiantao.c */
#include <stdio.h>

//extern 
int b = 888;
int go();

int main(){
	int i,j,k=200;

	if (-1) printf("external b=%d\n", b);
	go();
	int c(){//int *i, int *j){
		register int t;
		//t = *i; *i = *j; *j = t;
		t = i; i = j; j = t;
		printf("k= %d\n",k);
		return 1;
	}

	printf("i=%d j=%d \n",i = 1, j = 2);
	c();// &i, &j );
	printf("c(i,j); i=%d j=%d\n", i, j);
}