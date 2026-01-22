/**
 * -------------------------------------
 * @file  main.c
 * Assignment 1 Main Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include <stdlib.h>
#include <stdio.h>

#include "date_convert.h"
#include "falling_time.h"
#include "feet_to_acres.h"
#include "hypotenuse.h"
#include "leap_year.h"
#include "mow_lawn.h"
#include "sum_even.h"
#include "sum_partial_harmonic.h"

// Macro to convert a bool value of true (1) or false (0) to the strings "true" and "false"
// Uses the C ternary operator (See: https://www.freecodecamp.org/news/c-ternary-operator/)
#define BOOL_STR(x) ((x)?"true":"false")

/*
 * Test values are stored in constant arrays. Example:
 *     int values[] = {1900, 1996, 1997, 2000};
 * Defines an array of constant integer values - the contents of the array cannot be changed.
 *     double values[][2] = {{0.0, 0.0}, {1.0, 1.0}, {3.0, 4.0}};
 * Defines an array of pairs of double values.
 *
 *     int n = sizeof values / sizeof *values;
 * Stores the number of items in values in the variable n.
 * The caculation gets the entire size of values in memory (in bytes),
 * and divides that by the size of the first entry in values.
 *
 * Note that this works *only* in the same scope (i.e. code area) that
 * the array is defined in. This cannot be used, for example, to determine
 * the number of elements in an array passed as a parameter to a function.
 *
 * You may add more test values to these arrays - must recompile to see new results.
 */

void test_date_convert() {
    printf("------------------\n");
    printf("Test: date_convert\n\n");
    // parameter date format: DDMMYYYY
    int values[] = {1012000, 5012025, 12122000};
    int n = sizeof values / sizeof *values;

    for(int i = 0; i < n; i++) {
        int result = date_convert(values[i]);
        printf("date_convert(%d) -> %d\n", values[i], result);
    }
    printf("\n");
}

void test_falling_time() {
    printf("------------------\n");
    printf("Test: falling_time\n\n");
    // parameter date format: DDMMYYYY
    int values[] = {0, 425, 10000};
    int n = sizeof values / sizeof *values;

    for(int i = 0; i < n; i++) {
        int result = falling_time(values[i]);
        printf("falling_time(%d) -> %d\n", values[i], result);
    }
    printf("\n");
}

void test_feet_to_acres() {
    printf("------------------\n");
    printf("Test: feet_to_acres\n\n");
    // parameter date format: DDMMYYYY
    int values[] = {0, 43560, 125000};
    int n = sizeof values / sizeof *values;

    for(int i = 0; i < n; i++) {
        double result = feet_to_acres(values[i]);
        printf("feet_to_acres(%d) -> %lf\n", values[i], result);
    }
    printf("\n");
}

void test_hypotenuse() {
    printf("------------------\n");
    printf("Test: hypotenuse\n\n");
    // parameter date format: DDMMYYYY
    double values[][2] = {{0.0, 0.0}, {1.0, 1.0}, {3.0, 4.0}};
    int n = sizeof values / sizeof *values;

    for(int i = 0; i < n; i++) {
        double result = hypotenuse(values[i][0], values[i][1]);
        printf("hypotenuse(%lf, %lf) -> %lf\n", values[i][0], values[i][1], result);
    }
    printf("\n");
}

void test_leap_year() {
    printf("------------------\n");
    printf("Test: leap_year\n\n");
    int values[] = {1900, 1996, 1997, 2000};
    int n = sizeof values / sizeof *values;

    for(int i = 0; i < n; i++) {
        int result = leap_year(values[i]);
        printf("leap_year(%d) -> %s\n", values[i], BOOL_STR(result));
    }
    printf("\n");
}

void test_mow_lawn() {
    printf("------------------\n");
    printf("Test: mow_lawn\n\n");
    // parameter date format: DDMMYYYY
    double values[][3] = {{1.0, 1.0, 1.0}, {10.0, 40.0, 1.0}, {10.0, 40.0, 2.5}};
    int n = sizeof values / sizeof *values;

    for(int i = 0; i < n; i++) {
        double result = mow_lawn(values[i][0], values[i][1], values[i][2]);
        printf("mow_lawn(%lf, %lf, %lf) -> %lf\n", values[i][0], values[i][1], values[i][2], result);
    }
    printf("\n");
}

void test_sum_even() {
    printf("------------------\n");
    printf("Test: sum_even\n\n");
    int values[] = {0, 1, 5, 6};
    int n = sizeof values / sizeof *values;

    for(int i = 0; i < n; i++) {
        int result = sum_even(values[i]);
        printf("sum_even(%d) -> %d\n", values[i], result);
    }
    printf("\n");
}

void test_sum_partial_harmonic() {
    printf("------------------\n");
    printf("Test: sum_partial_harmonic\n\n");
    int values[] = {0, 1, 5, 6};
    int n = sizeof values / sizeof *values;

    for(int i = 0; i < n; i++) {
        double result = sum_partial_harmonic(values[i]);
        printf("sum_partial_harmonic(%d) -> %lf\n", values[i], result);
    }
    printf("\n");
}

/*
 * Comment out tests you do not wish to run.
 */
int main(int argc, char *argv[]) {
    test_date_convert();
    test_falling_time();
    test_feet_to_acres();
    test_hypotenuse();
    test_leap_year();
    test_mow_lawn();
    test_sum_even();
    test_sum_partial_harmonic();
    return EXIT_SUCCESS;
}
