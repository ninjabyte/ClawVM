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
typedef int16_t var; /* Variable */
typedef int8_t* array; /* Array pointer */

/* VM state variables */
typedef FILE* filePtr;
typedef uint32_t pc; /* Program counter pointer */
typedef uint8_t instr; /*  */

#endif /* TYPES_H_ */
