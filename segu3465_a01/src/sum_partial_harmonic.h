/**
 * -------------------------------------
 * @file  sum_partial_harmonic.h
 * Assignment 1 Functions Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 * DO NOT CHANGE
 */
#ifndef SUM_PARTIAL_HARMONIC_H_
#define SUM_PARTIAL_HARMONIC_H_

// Prototypes.

/**
 * Sums and returns the total of a partial harmonic series.
 * This series is the sum of all terms 1/i, where i ranges
 * from 1 to n (inclusive).
 * i.e. 1 + 1/2 + 1/3 + ... + 1/n
 *
 * @param n - an integer (> 0)
 * @return - the sum
 */
double sum_partial_harmonic(int n);

#endif /* SUM_PARTIAL_HARMONIC_H_ */
