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
typedef int16_t Var; /* Variable */
typedef int8_t* Array; /* Array pointer */

/* VM state variables */
typedef FILE* FilePtr;
typedef int32_t PC; /* Program counter pointer */

#endif /* TYPES_H_ */
