/* md.c mutiple dimension array */
#include <stdio.h>

int main(){
	int s[3][4];
	int k[3][4][5];
	int i,j;

	for(i=0;i < 3; i++){
		for (j=0; j < 4; j++){
			s[i][j] = (i+1)*10 + j + 1;
			printf("%d ", s[i][j]);
		}
		printf("\n");
	}

	int *p;
	p = &**s; // (int*)s;

	for(i=0;i < 3; i++){
		for (j=0; j < 4; j++){
			printf("%d ", *(p+i*4+j));
		}
		printf("\n");
	}

	printf("s=%p, s+1=%p\n", s, s+1);
	printf("k=%p, k+1=%p\n", k, k+1);
}