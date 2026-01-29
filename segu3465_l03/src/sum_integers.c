/**
 * -------------------------------------
 * @file  sum_integers.c
 * -------------------------------------
 * @author name, id, email
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
