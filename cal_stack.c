// cal_stack.c  for cal.c, stack pop and push

#include <stdio.h>
#define MAXVAL 20

int sp = 0; // stack point
double val[MAXVAL]; // stack

void push(double f){ 
	if (sp < MAXVAL)
		val[sp++] = f;
	else 
		printf("ERROR: stack full,can't push %g\n", f);
}

double pop(void){
	if (sp > 0)
		return val[--sp];
	else{
		printf("ERROR: stak empty\n");
		return 0.0;
	}
}