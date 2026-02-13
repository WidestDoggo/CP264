/**
 * -------------------------------------
 * @file  date_convert.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include <math.h>
int year, month, day, newDate;
#include "date_convert.h"

int date_convert(int date_number) {

    year = (date_number % 10000);
    month = (date_number % 1000000 / 10000);
    day = (date_number % 100000000 / 1000000);

    newDate = ((year * 100000) + (month * 1000) + (day * 10)) / 10;

    return newDate;
}
