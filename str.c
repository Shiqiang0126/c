// str.c
#include <stdio.h>
extern char *s;
// static
int sta_int = 100;
static int int2 = 200;
static char *s2 = "other line\n";

int p(){
	printf("there, is define %d:%s", sta_int,&s[6]);
	printf("%d : %s", int2, s2);
	{ int i=2; printf ("in the {%d}\n",i ); }
	// printf ("out of the {%d}\n",i ); 
}

char *s="Hello World!\n";