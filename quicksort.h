#ifndef QUICKSORT_H
#define QUICKSORT_H

void quicksort(int *arr, int low, int high);
void debug_arr(int *arr, int i, int j, int pivot, int array_length);
void delay(unsigned int milliseconds);
void swap(int *a, int *b);
void print_dashline(int n);

#define ARRAY_LENGTH 4
#endif
