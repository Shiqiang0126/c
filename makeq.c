// makeq.c
#include <stdio.h>
#include <stdlib.h>

int main(){
	int s[26];
	int i;

	for (i=0; i<26; i++){
		s[i] = 'A' + i;
		printf("%c ", s[i]);
	}
	printf("\n");

	int v[10];
	int *p = s;

	v[0] = *p;
	v[1] = *p++;
	v[2] = *p;
	v[3] = *++p;
	v[4] = *p;
	v[5] = *(p += 10);
	v[6] = *p--;
	v[7] = *p;
	v[8] = *--p;
	v[9] = *p;

	for (i=0; i<10; i++){
		printf("%1d:%c  ",i,v[i]);
	}
	printf("\n");
	printf("%c \n", --*p);

	for (i=0; i<26; i++){
		printf("%c ", s[i]);
	}
	printf("\n");
}