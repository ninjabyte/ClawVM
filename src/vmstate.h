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
	file_t file; /* Input file */
	pcptr_t pc; /* Program counter */
	var_t stack[STACK_SIZE]; /* Global stack */
} vmstate_t;

#endif /* VMSTATE_H_ */
