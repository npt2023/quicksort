#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "quicksort.h"
#include "helper.h"


/* QUICKSORT.C:
 *
 * This file includes the quicksort sorting algorithm and 
 * some functions for debugging
 *
 */
/*
 *
 * quicksort: A recursive sorting algorithm
 *
 * This implementation takes in an array, selects the 
 * rightmost element as a partition element, and with
 * each recursion makes sure that it gets positioned so
 * that every element to the left of it is less than it
 * and every element to the right of it is greater than it.
 *
 * A debug function is included to see what the function is actually
 * doing
 *
 */



void quicksort(int *arr, int low, int high) {
    if(low >= high) return;
    int i = low;
    int j = high-1;
    for(;;)
    {
        while(arr[i] <= arr[high] && i < high) {
            i++;	
        }
	while(arr[j] > arr[high] && j > low) {
	    j--;
	}
	/* Prints the array with respect to i, j, and the partitioning
	 * element
	 */
	debug_arr(arr, i, j, high, ARRAY_LENGTH);
	if(i < j)
	{
   	    swap(&arr[i], &arr[j]);
	}
	if(j <= i)
	{
	    swap(&arr[i], &arr[high]);
	    break;
	}
    }
    quicksort(arr, low, i-1);
    quicksort(arr, i+1, high);
}

/*
 * void delay(unsigned int milliseconds)
 * Define our own delay function as the
 * default one defined in <unistd.h> only takes microseconds as an
 * argument
 *
 */
void delay(unsigned int milliseconds) {
    usleep((useconds_t) milliseconds * 1000);
}


/* debug_arr: prints the quicksort array
 * as well as the locations of i and j 
 * and pivot
 * under the array
 */
/* EXAMPLE OUTPUT:
 * 
 * Value of i: 0, value of j: 6
 * Value of pivot: 7
 * ----------------------------------------------------------------
 *     1   2   5   8   9   19   21
 *     i                    j    p
 * ----------------------------------------------------------------
 *
 */


void debug_arr(int *arr, int i, int j, int pivot, int array_length)
{
    int pos;
    bool isInitialized = false;
    HelperObject myObject = create();
    printf("Value of i: %d, value of j: %d\n", i, j);
    printf("Value of pivot p: %d\n", pivot);
    /* 
     * Traverse the array. Print a newline for every 10 elements.
     * When a pivot element, i, or j detected, call the helper function
     * to print their relative location under the array segment
     *
     */
    for(pos = 0; pos <= array_length; pos++) {
        if(Dec(pos) == 0 || pos == array_length) { // Print a newline every 10 elements, or when array
        //_length is reached
            printf("\n");
            if(isInitialized) {
                run(myObject);
                uninitialize(myObject);
                isInitialized = false;      
                printf("\n");
	    }
        }
        if(pos == array_length) break;
        printf("%4d", arr[pos]); // Print each element one by one
        if(pos == i) {
            isInitialized = true;
            initialize(myObject, "i", Dec(i));
        }
        if(pos == j) {
            isInitialized = true;
	    initialize(myObject, "j", Dec(j));
        }
        if(pos == pivot) {
            isInitialized = true;
	    initialize(myObject, "p", Dec(pivot));
        }
    }
/* We are done */
    print_dashline(50);
}

	

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b, *b = tmp;
    return;
}

void print_dashline(int n) {
    int i = 0;
    while(i++ < n)
        putchar('-');
    putchar('\n');
}
