/**
 * -------------------------------------
 * @file  functions.c
 * -------------------------------------
 * @author Jack Seguin, 169083465, segu3465@mylaurier.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {
    int a, b, c;
    int ch;
    printf("Enter three comma-separated integers: \n");

    while (scanf("%d,%d,%d", &a, &b, &c) != 3){
        printf("The integers were not properly entered.\n");
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    
    return a + b + c;

}   
