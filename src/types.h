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
typedef int16_t ClawNumber; /* Variable */
typedef int8_t* ClawArray; /* Array pointer */

/* VM state variables */
typedef FILE* FilePtr;
typedef uint32_t PC; /* Program counter pointer */
typedef uint8_t Instruction; /* Instruction */
typedef ClawNumber OpStack[];

#endif /* TYPES_H_ */
