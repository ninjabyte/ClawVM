#ifndef VM_H_
#define VM_H_

#include <stdio.h>
#include <stdint.h>
#include "opcodes.h"
#include "mem/ClawStack.h"

#define STATE_IDLE 0
#define STATE_RUNNING 1
#define STATE_EOF 2
#define STATE_ERROR 3

typedef struct {
	FILE* code; /* Input file */

	uint32_t pc; /* Program counter */
	uint8_t state; /* State of the virtual machine */
	uint8_t errorCode; /* Error code, if any */

	ClawStack_t varStack; /* variable stack */
	ClawStack_t stack; /* operation stack */

	/* TODO Environment variable for native functions */
} VMState;

void vm_init(VMState* vm, FILE* file);
void vm_destroy(VMState* vm);
void vm_error(VMState* vm, uint8_t error);
void vm_stackdump(VMState* vm);
uint8_t vm_fetch(VMState* vm);
int vm_run(VMState* vm);
void vm_executeNext(VMState* vm, opcode_t instr);

#endif /* VM_H_ */
