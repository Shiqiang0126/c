// zone.c
#include <stdio.h>

extern char *s;
extern int sta_int;
int p(void); // 函数可以省略extern

int main(){
	p();
	printf("%d:%s\n", sta_int,s);
}