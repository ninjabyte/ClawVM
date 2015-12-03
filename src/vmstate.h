/*
 * vmstate.h
 *
 *  Created on: 23.11.2015
 *      Author: Benedikt
 */

#ifndef VMSTATE_H_
#define VMSTATE_H_

#include "types.h"
#include <stdint.h>

#ifndef STACK_SIZE
#define STACK_SIZE 512
#endif

typedef struct {
	FilePtr File; /* Input file */
	PC PC; /* Program counter */
//	OpStack Stack[STACK_SIZE]; /* Global stack */
	uint8_t IsRunning;
	uint8_t Error;
} VMState;

#endif /* VMSTATE_H_ */
