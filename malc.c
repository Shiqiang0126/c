/* malc.c memory alloc test */
#include <stdio.h>
#include <stdlib.h>

#define Size1 (4)
#define Size2 (3)
#define Size3 (5)
 
int main() {
  int* a1 = (int*)malloc(4 * sizeof(int)); /*16 bytes*/
  int* a2 = malloc(3 * sizeof(int)); /*12 bytes*/
  int* a3 = malloc(5 * sizeof(int)); /*20 bytes*/
  a1[0] = 1; a1[1] = 2; a1[2] = 3; a1[3] = 4; /*filling array a1*/
  a2[0] = 9; a2[1] = 8; a2[2] = 7; /*filling array a2*/
  a3[0] = -1; a3[1] = -2; a3[2] = -3; a3[3] = -4; a3[4] = -5; /*filling array a3*/
 
  int sizes[ ] = {Size1, Size2, Size3, 0}; /*local array of sizes*/
 
  int** ptr2ptr = malloc(sizeof(int*) * 4); /*array of 16 bytes*/
  ptr2ptr[0] = a1; /*storing the pointer to a1 in first element*/
  ptr2ptr[1] = a2; /*storing the pointer to a2 in second element*/
  ptr2ptr[2] = a3; /*storing the pointer to 03 in second element*/
  ptr2ptr[3] = 0; /* this is the null pointer for termination*/
 
  int i = 0;
  /*here we are looping until we dont reach the null terminator which ptr2ptr[3]*/
  while (ptr2ptr[i]) {
    int j;
    for (j = 0; j < sizes[i]; j++) /*for each loop print out the contents of the pointer and increment i*/
      printf("%i ", ptr2ptr[i][j]);
    printf("\n");
    i++; /*increment i*/
  }
  return 0;
}