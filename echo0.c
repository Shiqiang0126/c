/* echo0.c */
#include <stdio.h>

int main(int argc, char *argv[]){
	while (--argc)
//		printf("%s%s", *++argv, (argc >1)? " " : "");
		printf((argc > 1)?"%s ":"%s", *++argv);
	printf("\n");
} 