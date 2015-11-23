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
	filePtr file; /* Input file */
	pc pc; /* Program counter */
	var stack[STACK_SIZE]; /* Global stack */
} vmState;

#endif /* VMSTATE_H_ */
