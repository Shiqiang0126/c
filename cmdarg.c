/* cmdarg.c command line argment test */
//#include <stdlib.h>
#include <stdio.h>
//#include <errno.h>

int main(int argc, char **argv){

	for (int i = 0; i < argc; i++)
		printf("%s ", *(argv+i));
	printf("\n");

	printf("%s %c %c %p\n", "xyz"+1, "ABCDEFG"[2], *("1234" + 1), "123456789"+4);
	// printf("%s\n", NCOL);
	if (fopen("kk.kkk","r") == NULL) perror("TEST here");
	}
}