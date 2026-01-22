/**
 * -------------------------------------
 * @file  falling_time.c
 * Assignment 1 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 */
#include <math.h>

#include "falling_time.h"

int time;

int falling_time(int distance) {

    time = sqrt(2 * distance / GRAVITY_ACCEL) ;

    return time;
}
