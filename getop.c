// getop.c  for stack.c 

#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'

char getch(void);
void ungetch(char c); 

char getop(char s[]){
	int i;
	char c;

	while ((s[0] = c = getch()) == ' ' || c == '\t') //只有对求值次序很笃定才敢这么写
		;
	s[1] = '\0';
	if (!isdigit(c) && c!='.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if ( c != EOF )
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

char getch(void){
	return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(char c){
	if (bufp >= BUFSIZE)
		printf("ungetch: too many charactoers unget\n");
	else
		buf[bufp++] = c;
}