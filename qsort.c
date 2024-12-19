// qsort.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *v, int i, int j);
void qsort0(int *, int, int);

int main(){
	int s[30];
	int i;

	srand((unsigned) time(NULL));
	printf("org------\n");
	for (i=0; i<30; i++){
		s[i] = 'A' + rand() % 26;
		printf("%c ", s[i]);
	}
	qsort0(s,0,29);
	printf("\nsorted---\n");
	for (i=0; i<30; i++)
		printf("%c ", s[i]);
	printf("\n");
}

void qsort0(int *v, int left, int right){
	int i, last;
	if (left >= right)
		return;
	swap(v, left, (left+right)/2); // left 放“中值”
	last = left; // last 指向有数，加了再用，用了再减
	for (i = left+1; i <= right; i++)
		if (v[i] < v[left]) // 与“中值”比较，进行‘归拢’
			swap(v, ++last, i); 
	swap(v, left, last); // last位的那个“中值”，归位

	qsort0(v, left, last-1);
	qsort0(v, last+1, right); // '中值'不参与下一轮
}

void swap(int v[], int i, int j){
	int temp;

	temp = v[i]; v[i] = v[j]; v[j] = temp;
}