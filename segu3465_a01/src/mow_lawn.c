/**
 * -------------------------------------
 * @file  mow_lawn.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include <math.h>

#include "mow_lawn.h"
double area;
double mowingTime;

int mow_lawn(double width, double length, double speed) {
    area = width * length;
    mowingTime = area / speed;

    return mowingTime;
}
