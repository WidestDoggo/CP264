/**
 * -------------------------------------
 * @file  leap_year.c
 * Assignment 1 Functions Header File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include "leap_year.h"

bool leap_year(int year) {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    if (year % 4 == 0) {
        return true;
    }
    return false;
}