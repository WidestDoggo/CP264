/**
 * -------------------------------------
 * @file  hypotenuse.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include <math.h>

#include "hypotenuse.h"

double side3;

double hypotenuse(double side1, double side2) {

    side3 = sqrt(pow(side1, 2.0) + pow(side2, 2.0));

    return side3;
}
