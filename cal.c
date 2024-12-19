/* cal.c  a RPN caclulator */

// compile with getop.c cal_stack.c

#include <stdio.h>
#include <stdlib.h> // for atof()

#define MAXOP 100
#define MAXLINE 1000
#define NUMBER '0'

char getop(char []); // why not : char gotop(char [])
void push(double);
double pop(void);
//int my_getline(char s[], int lim);

int main(){
	char type; // why not: char
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF){
		switch (type){
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0){
				push(pop() / op2);
			} else {
				printf("ERROR: zero deivision\n");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("ERROR: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}