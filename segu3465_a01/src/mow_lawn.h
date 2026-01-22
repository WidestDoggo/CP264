/**
 * -------------------------------------
 * @file  mow_lawn.h
 * Assignment 1 Functions Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 * DO NOT CHANGE
 */
#ifndef MOW_LAWN_H_
#define MOW_LAWN_H_

// Prototypes.

/**
 * Determines how long it takes to mow a rectangular lawn.
 *
 * @param width - width of a lawn in metres
 * @param length - length of a lawn in metres
 * @param speed - square metres cut per minute
 * @return - time required to mow the lawn in minutes
 */
int mow_lawn(double width, double length, double speed);

#endif /* MOW_LAWN_H_ */
