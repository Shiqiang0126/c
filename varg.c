/* varg.c var arg */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int vprint ( char fmt[], ... ){
	int i, n = strlen(fmt);
	va_list var_arg;

	va_start(var_arg, n);
	for (i = 0; i < n; i++){
		switch (fmt[i]) {
		case 'i':
			printf("i:%d ", va_arg(var_arg, int));
			break;
		case 'c':
			printf("c:'%c' ", (char) va_arg(var_arg, int));
			break;
		case 'f':
			printf("f:%f ", (float) va_arg(var_arg, double));
			break;
		default:
			printf("Invalid fmt.\n");
			return 1;
		}
	}
	printf("\n");
	va_end(var_arg);
	return 0;
}

int main(){
	vprint("iii", 10, 20, 30);
	vprint("ccc", 'a', 'b', 'c');
	vprint("fff", 1.0, 3.14, 5.88);
	vprint("icf", 100, 'A', 1.414);
}