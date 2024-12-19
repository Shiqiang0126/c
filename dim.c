/* dim.c dimention test */
#include <stdio.h>

int fun(char s[], int n){
	int i;
	for (i=0; i < n; i++) *s++ = 'f';
	*s = '\0';
	printf("sizeof(s) in fun = %d\n", sizeof(s));
}

char s3[30] = "XXHXXX";
int main(){
	char s[10],ss[20]="ssss";
	int i;
	char *ptr,**p;

	if (&s[0] == (char*)&s) printf(" &s[0] == &s\n");
	for (i=0; i<10; i++) *(s+i) = 'c';
	s[10] = '\0';
	printf("sizeof(s) in main = %d\n", sizeof(s));
	printf("%s\n", s);
	fun (s, 10);
	printf("%s\n", s);
	ptr = s;
	printf("%c, %p, %p\n", *ptr, ptr, &ptr);
	ptr = ss;
	printf("%c, %p, %p\n", *ptr, ptr, &ptr);
	ptr = s3;
	p = &ptr;
	printf("%c, %p, %p\n", *ptr, ptr, &ptr);
	printf("%c, %p, %p, %p\n", **p, *p, p, &p);
	printf("%c\n", 2[s3]);
}