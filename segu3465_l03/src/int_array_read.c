/**
 * -------------------------------------
 * @file  int_array_read.c
 * -------------------------------------
 * @author Jack Seguin, 169083465, segu3465@mylaurier.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {
    int value;
    int ch;
    //int array[size];
    printf("Enter %d values for an array of int.\n", size);
    for (int i = 0; i < size; i++) {
        printf("%s%d%s", "Value for index ", i, ": ");
        if (scanf("%d", &value) == 1)  {
            array[i] = value;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
        else {
            printf("Not a valid integer\n");
            i--;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }   
    }
}
