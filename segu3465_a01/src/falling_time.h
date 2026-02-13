/**
 * -------------------------------------
 * @file  falling_time.h
 * Assignment 1 Functions Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 * DO NOT CHANGE
 */
#ifndef FALLING_TIME_H_
#define FALLING_TIME_H_

// Constants.
#define GRAVITY_ACCEL 9.8   // m/s^2

// Prototypes.

/**
 * Calculates time an object takes to fall a certain distance due to gravity.
 * Uses the GRAVITY_ACCEL constant.
 *
 * @param distance - distance object has fallen in metres.
 * @return time object takes to fall in seconds.
 */
int falling_time(int distance);

#endif /* FALLING_TIME_H_ */
