/* MAIN.c
 * Write a program that implements the quicksort algorithm, and
 * shows the positions of i, j, and pivot for each
 * recursion of quicksort. 
 * 
 * This file serves an entry point for the program with the `main` function. 
 * 
 * This file creates an array of ARRAY_LENGTH, defined in the header file `quicksort.h`, 
 * which is included in this file. 
 * 
 * EXAMPLE PROGRAM OUTPUT:
 * 
Contents of array arr (unsorted):

  10  10   4   0
--------------------------------------------------
Running the quicksort function: 
Value of i: 0, value of j: 0
Value of pivot p: 3

  10  10   4   0
   i
   j           p                        
--------------------------------------------------
Value of i: 3, value of j: 2
Value of pivot p: 3

   0  10   4  10
           j   i
               p                        
--------------------------------------------------
Value of i: 1, value of j: 1
Value of pivot p: 2

   0  10   4  10
       i
       j   p                            
--------------------------------------------------
Contents of array arr (sorted)
   0   4  10  10
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "quicksort.h"

#define HIGH (ARRAY_LENGTH-1) // The last element in the array
#define MAX_INT 10 // The maximum number that can be stored in an array element
void print_arr(int *arr, int n);

int main(void)
{
    int arr[ARRAY_LENGTH] = {0};
    srand((unsigned int) time(NULL));
    for(int i = 0; i < ARRAY_LENGTH; i++) 
    {
        arr[i] = rand() % (MAX_INT+1); /* 0 to MAX_INT */
    }
    printf("Contents of array arr (unsorted):\n");
    print_arr(arr, ARRAY_LENGTH);
    print_dashline(50);
    printf("Running the quicksort function: \n");
    quicksort(arr, 0, HIGH);
    printf("Contents of array arr (sorted)");
    print_arr(arr, ARRAY_LENGTH);
    print_dashline(50);
    return 0;
}

/* print_arr: Print the array one element at a time */

void print_arr(int *arr, int n) {
    int i;
    for(i = 0; i < n; i++) {
	if((i % 10) == 0) printf("\n");
       	    printf("%4d", arr[i]);
	}
    putchar('\n');
}
