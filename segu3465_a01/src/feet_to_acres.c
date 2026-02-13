/**
 * -------------------------------------
 * @file  feet_to_acres.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include <math.h>

#include "feet_to_acres.h"

double acres;

double feet_to_acres(int square_feet) {

    acres = square_feet / 43560.0;

    return acres;
}

