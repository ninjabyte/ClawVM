/*
 * vmstate.h
 *
 *  Created on: 23.11.2015
 *      Author: Benedikt
 */

#ifndef VMSTATE_H_
#define VMSTATE_H_

#include "types.h"

#ifndef STACK_SIZE
#define STACK_SIZE 512
#endif

typedef struct {
	FilePtr file; /* Input file */
	PC pc; /* Program counter */
	Var stack[STACK_SIZE]; /* Global stack */
} vmstate_t;

#endif /* VMSTATE_H_ */
