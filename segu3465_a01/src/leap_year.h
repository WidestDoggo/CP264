/**
 * -------------------------------------
 * @file  leap_year.h
 * Assignment 1 Functions Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 * DO NOT CHANGE
 */
#ifndef LEAP_YEAR_H_
#define LEAP_YEAR_H_

#include <stdbool.h>

/**
 * Determines if a year is a leap year. Every year that is
 * exactly divisible by four is a leap year, except for years
 * that are exactly divisible by 100, but these centurial years
 * are leap years if they are exactly divisible by 400. For
 * example, the years 1700, 1800, and 1900 are not leap years,
 * but the years 1600 and 2000 are.
 *
 * @param year - The year to test
 * @return - true if year is a leap year, false otherwise
 */
bool leap_year(int year);

#endif /* LEAP_YEAR_H_ */
