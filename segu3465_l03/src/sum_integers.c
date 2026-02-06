/**
 * -------------------------------------
 * @file  sum_integers.c
 * -------------------------------------
 * @author Jack Seguin, 169083465, segu3465@mylaurier.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_integers(void) {
    int value;
    int sum = 0;
    
    printf("Enter integers, one per line:\n");
    while (scanf("%d", &value) == 1){
        sum += value;
    }
    
    // Clear leftover output
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    return sum;
}
