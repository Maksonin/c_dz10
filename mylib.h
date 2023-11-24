#include <stdio.h>
#include <stdlib.h>

#include "mylib.c"

void hello(void);
int setIntVar(char str[]);
void setIntArray(int arr[], int size);
void setRandomIntArray(int arr[], int size, int seed);
void setQuardIntArray(int arr[], int ncol, int nrow, int seed);
void printIntArray(int arr[], int size);
// void printString(char str[], int size);
void printQuardIntArray(int arr[], int ncol, int nrow);
void shiftArrayRight(int arr[], int size, int shiftLen);
void swap(int *pa, int *pb);
void swapChar(char *pa, char *pb);
void sortArray(int a[], int size, _Bool direction);