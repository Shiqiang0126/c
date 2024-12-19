// str2char.c  

#include <stdio.h>

void main(){
	char s[][5] = {"123", "abc"};
	int i = 0;

	while (s[0][i] != 0){
		printf("%c",s[0][i]);
		i++;
	}

	return;
}