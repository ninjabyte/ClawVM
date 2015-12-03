#include <stdio.h>
#include "vm.h"
#include "opcodes.h"
#include "error/error.h"
#include "mem/stack.h"

void vm_error(VMState* vm, uint8_t error);
uint8_t vm_fetchByte(VMState* vm);

/* initialize a virtual machine */
void vm_init(VMState* vm, FILE* file)
{
	vm->code = file;
	vm->state = STATE_IDLE;
	vm->errorCode = ERR_NO_ERROR;
	stack_create(&vm->stack, 32);
}

/* set the vm to an error state */
void vm_error(VMState* vm, uint8_t error)
{
	vm->state = STATE_ERROR;
	vm->errorCode = error;
}

/* fetch the next byte */
uint8_t vm_fetchByte(VMState* vm)
{
	int data = fgetc(vm->code);
	if (data == EOF)
	{
		vm->state = STATE_EOF;
		return IN_NOP;
	}

	return (uint8_t) data;
}

/* run the virtual machine */
int vm_run(VMState* vm)
{
	vm->state = STATE_RUNNING;
	opcode_t instr = (opcode_t) vm_fetchByte(vm);
	while (vm->state == STATE_RUNNING)
	{
		vm_executeNext(vm, instr);
		instr = (opcode_t) vm_fetchByte(vm);
	}

	return vm->errorCode;
}

/* execute the next instruction */
void vm_executeNext(VMState* vm, opcode_t instr)
{
	switch(instr) {
		case IN_NOP:
			break;
		default:
			break;
	}
}
