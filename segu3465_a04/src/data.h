/** @file  data.h
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 * Comment out data types not in use.
 * data_type is defined as an alias to an external data type.
 */
#ifndef DATA_H_
#define DATA_H_

#define BOOL_STR(x) ((x)?"true":"false")  // converts bool type to string

// Uncomment one of the following to use the matching data type
#define USE_INT
//#define USE_FOOD
//#define USE_STRING
//#define USE_CHAR

#ifdef USE_INT

// ========================================
// Definitions for integer data

#include "int_data.h"

// defines 'data_type' as an alias to some other type.
typedef int_struct data_type;

// defines aliases for 'data_type' functions
#define data_copy(x, y) int_copy(x, y)
#define data_string(x, y, z) int_string(x, y, z)
#define data_compare(x, y) int_compare(x, y)
#define data_from_string(x, y) int_from_string((x), (y))

#endif

#ifdef USE_FOOD

// ========================================
// Definitions for food data

#include "food_utilities.h"

#define DATA_STRING_SIZE 2048

// defines 'data_type' as an alias to some other type.
typedef food_struct data_type;

// defines aliases for 'data_type' functions
#define data_copy(x, y) food_copy(x, y)
#define data_string(x, y, z) food_string(x, y, z)
#define data_compare(x, y) food_compare(x, y)

#endif

#ifdef USE_STRING

// ========================================
// Definitions for string data
#include "string_data.h"

// defines 'data_type' as an alias to some other type.
typedef string_struct data_type;

// defines aliases for 'data_type' functions
#define data_copy(x, y) string_copy((x), (y))
#define data_string(x, y, z) string_string((x), (y), (z))
#define data_compare(x, y) string_compare((x), (y))
#define data_from_string(x, y) string_from_string((x), (y))

#endif

#ifdef USE_MOVIE

// ========================================
// Definitions for movie data

 #include "movie.h"

 #define DATA_STRING_SIZE 2048

 // defines 'data_type' as an alias to some other type.
 typedef movie_struct data_type;

 // defines aliases for 'data_type' functions
 #define data_copy(x, y) movie_copy(x, y)
 #define data_print(x) movie_print(x)
 #define data_compare(x, y) movie_compare(x, y)

#endif

#ifdef USE_CHAR

// ========================================
// Definitions for char data

#include "char_data.h"

// defines 'data_type' as an alias to some other type.
typedef char_struct data_type;

// defines aliases for 'data_type' functions
#define data_copy(x, y) char_copy(x, y)
#define data_string(x, y, z) char_string(x, y, z)
#define data_compare(x, y) char_compare(x, y)
#define data_from_string(x, y) char_from_string((x), (y))

#endif

#endif /* DATA_H_ */
