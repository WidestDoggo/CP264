/**
 * -------------------------------------
 * @file  sum_partial_harmonic.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include "sum_partial_harmonic.h"
double parSum;

double sum_partial_harmonic(int n) {

    for (int i = 0; i <= n; i++) {
        parSum += 1/i;
    }
      

    return parSum;
}
