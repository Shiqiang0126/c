/* test.c  programm templet*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct xt {
	int a;
	int b;
	int c;
} x, y;

struct pt {
	int a;
	int b;
	int c;
} *p;

size_t sl(char *s){
	int p = 0;
	while ( *(s+p++) != 0 )
		;
	return p-1;
}

int main(){
	char s[]="1 + 2 + 1 + 	5";
	char *token;
	int i, j = strlen(s);

	for( i = 0; i < 20; i++)
		printf("%s:%d\n", itoa(i,s,10),strspn(itoa(i, s, 10), "0123456789"));
	char *ss= "123445";

	printf("%s %d\n", ss, atoi(ss));
	printf("ss= %s\n", ss);
	exit(0);

	token = strtok(s," \t");
	while( token != NULL){
		for(i = 0; i < j; i++)
		printf("%c", s[i]);
		printf("\n");
		printf("token<%s>\n", token);
		token = strtok(NULL, " \t");
	}
	exit(0);


	//char s[10];
	printf("%s", strcpy(s, NULL));
	exit(0);

	printf("%d\n", strcspn( "+*()", "+"));
	printf("%d\n", strcspn( "+*()", "*"));
	printf("%d\n", strcspn( "+*()", "("));
	printf("%d\n", strcspn( "+*()", ")"));
	printf("%d\n", strcspn( "+*()", ";"));
	exit(0);

	if ( ((unsigned int) 2 - (unsigned int) 5 )< 0){
		printf("good!\n");
	} else {
		printf("NOT good!\n");
	}
	printf("%d\n", sl("123456789"));
	printf("%d\n", sl("Hello World!"));
	x.a = 10; x.b = 88; x.c = 99;
	// p = &x;
	printf("%d %d %d \n", p->a, p->b, p->c);
	y = x;
	printf("%d %d %d \n", y.a, y.b, y.c);
}
//	printf("%d\n", 