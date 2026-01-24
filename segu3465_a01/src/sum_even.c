/**
 * -------------------------------------
 * @file  sum_even.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include "sum_even.h"
int sum;

int sum_even(int n) {

    for (int i = 0; i <= n; i++) {
      if (i % 2 == 0) {
        sum += i;
      }

    }

    return sum;
}
