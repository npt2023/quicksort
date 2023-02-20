/* helperADT.c: 
 *
 * Create an Abstract-Data-Type (ADT)
 * named HelperObject. HelperObject
 * is a pointer to a structure
 * containing the positions of i, j, and the
 * pivot element for an array segment
 * defined by debug_quicksort in quicksort.c
 *
 * The positions of the variables within the object
 * will be of Decimal type ((int) 0-9), as the array
 * segment defined by debug_quicksort is 10 elements
 * long
 *
 * The functions defined in this file are as follows:
 *
 * 1. Write a function that creates a
 * dynamically allocated ADT
 * 2. Write a function that can initialize the elements
 * in the ADT
 * 3. Write a function that can uninitialize the elements
 * in the ADT
 * 4. Write a function that prints the location of i, j,
 * and p under an array segment created by debug_quicksort
 * 5. Write a function that can convert an array value
 * into a Decimal value, indicating a position under an
 * array segment
 *
 */

#include "helper.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define the ADT, which includes the 
 * positions of i, j, and the pivot element */

struct helper_s {
	Decimal i;
	Decimal j;
	Decimal p;
};

/* *****************************************
 * HelperObject create(void);              *
 *                                         *
 *                                         *
 * This function creates the ADT           *
 * as uninitialized                        *
 * and terminates the program in the event *
 * of a memory allocation error            *
 * *****************************************
 */
HelperObject create(void) {
	HelperObject new_object;
	new_object = (struct helper_s *)malloc(sizeof(struct helper_s));
	if(new_object == NULL) {
		printf("\nerror in allocating a helper object\n");
		exit(EXIT_FAILURE);
	}
    new_object->i = -1;
    new_object->j = -1;
    new_object->p = -1;
	return new_object;
}

/*********************************************************************
 * void initialize(HelperObject s, const char *pos, Decimal val);    *
 *                                                                   *
 * This function will initialize variables i, j, and p in the Helper *
 * Object abstract data type (ADT).                                  *
 *                                                                   *
 * Choose the variable by passing the function a pointer to a string *
 * that is "i", "j", or "p". Since the array segment is 10 elements  *
 * long, the variables will not be greater than 9, so use the        *
 * Decimal type defined in helper.h                                  *
 * *******************************************************************
 *
 */

void initialize(HelperObject s,  const char *pos, Decimal val) {
	if(!strcmp(pos, "i"))
		s->i = val;
	if(!strcmp(pos, "j"))
		s->j = val;
	if(!strcmp(pos, "p"))
		s->p = val;
}

/* void uninitialize(HelperObject s);
 *
 * This function nullifies the value of elements defined 
 * in the Abstract Data Type (ADT).
 */

void uninitialize(HelperObject s) {
    s->i = -1;
    s->j = -1;
    s->p = -1;
}
/* *****************************************************
 * void run(helperObject s);                           *
 *                                                     *
 * This function prints the location                   *
 * of i, j, and p under a 10 element                   *
 * array segment as indicated by debug_quicksort       *
 *                                                     *
 * If either i, j, or p point to the same element,     *
 * use a newline and write their location underneath   *
 * *****************************************************
 *
 */
void run(HelperObject s) {
	int x, y;
    
	for(x = 0; x < 10; x++) {
		if(x == s->i) {
			printf("   i");
		}
		if(x == s->j) {
			if(s->j == s->i) {
				printf("\n");
                for(y = 0; y < s->j; y++) {
                    printf("    ");
                }
            }
			printf("   j");
		}
		if(x == s->p) {
            if(s->p == s->i || s->p == s->j) {
                printf("\n");
                for(y = 0; y < s->p; y++) {
                    printf("    ");
                }
            }
			printf("   p");
		}
		if(x != s->i && x != s->j && x != s->p)
			printf("    ");
	}	
}


/* Decimal Dec(int i); ***************************************
 * Convert integer i to a single digit (0-9) to be compatible*
 * with indicating the position of i, j, or p                *
 * under an array segment as indicated by debug_quicksort    *
 * ***********************************************************
 */

Decimal Dec(int i) {
	return (Decimal)(i % 10);
}
