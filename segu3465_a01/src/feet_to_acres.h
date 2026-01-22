/**
 * -------------------------------------
 * @file  feet_to_acres.h
 * Assignment 1 Functions Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 * DO NOT CHANGE
 */
#ifndef FEET_TO_ACRES_H_
#define FEET_TO_ACRES_H_

// Constants.
#define FEET_PER_ACRE 43560.0

// Prototypes.

/**
 * Converts square footage to acres.
 * Uses the FEET_PER_ACRE constant.
 *
 * @param square_feet - area in square feet
 * @return - square footage in acres
 */
double feet_to_acres(int square_feet);

#endif /* FEET_TO_ACRES_H_ */
