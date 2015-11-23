/*
 * types.h
 *
 *  Created on: 23.11.2015
 *      Author: Benedikt
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <stdint.h>

/* Claw types */
typedef int16_t var_t; /* Variable */
typedef int8_t* array_t; /* Array pointer */

/* VM state variables */
typedef FILE* file_t;
typedef int32_t pcptr_t; /* Program counter pointer */

#endif /* TYPES_H_ */
