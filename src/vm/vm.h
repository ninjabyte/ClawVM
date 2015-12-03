#ifndef VM_H_
#define VM_H_

#include <stdio.h>
#include <stdint.h>
#include "opcodes.h"
#include "mem/stack.h"

#define STATE_IDLE 0
#define STATE_RUNNING 1
#define STATE_EOF 2
#define STATE_ERROR 3

typedef struct {
	FILE* code; /* Input file */

	uint32_t pc; /* Program counter */
	uint8_t state; /* State of the virtual machine */
	uint8_t errorCode; /* Error code, if any */

	stack_t stack;

	/* TODO Environment variable for native functions */
} VMState;

void vm_init(VMState* vm, FILE* file);
int vm_run(VMState* vm);
void vm_executeNext(VMState* vm, opcode_t instr);

#endif /* VM_H_ */
