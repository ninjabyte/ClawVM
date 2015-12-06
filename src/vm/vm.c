#include <stdio.h>
#include <stdint.h>
#include "vm.h"
#include "opcodes.h"
#include "error/error.h"
#include "mem/ClawStack.h"
#include "instructions/arithmetic.h"
#include "instructions/load.h"

/* initialize a virtual machine */
void vm_init(VMState* vm, FILE* file)
{
	vm->code = file;
	vm->state = STATE_IDLE;
	vm->errorCode = ERR_NO_ERROR;
	stack_create(&vm->varStack, 32);
	stack_create(&vm->stack, 32);
}

void vm_destroy(VMState* vm)
{
	stack_destroy(&vm->stack);
	stack_destroy(&vm->varStack);
}

/* set the vm to an error state */
void vm_error(VMState* vm, uint8_t error)
{
	vm->state = STATE_ERROR;
	vm->errorCode = error;
}

void vm_stackdump(VMState* vm)
{
	int i;
	for (i=0; i<vm->stack.top; i++)
	{
		uint8_t type = vm->stack.data[i].type;
		printf("|%i", type);
		if (type == TYPE_NUMBER)
			printf(": %i", (int) vm->stack.data[i].data_number);
		if (type == TYPE_VARIABLE)
			printf(": %i", (int) (int16_t) vm->stack.data[i].data_variable.id);
	}
	printf("|\n");
}

/* fetch the next byte */
uint8_t vm_fetch(VMState* vm)
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
	opcode_t instr = (opcode_t) vm_fetch(vm);
	while (vm->state == STATE_RUNNING)
	{
		vm_executeNext(vm, instr);
		instr = (opcode_t) vm_fetch(vm);
	}

	return vm->errorCode;
}

/* execute the next instruction */
void vm_executeNext(VMState* vm, opcode_t instr)
{
	switch(instr) {
		case IN_NOP:
			break;
		case IN_ADD:
			aritmetic_add(vm);
			break;
		case IN_SUB:
			aritmetic_sub(vm);
			break;
		case IN_MUL:
			aritmetic_mul(vm);
			break;
		case IN_DIV:
			aritmetic_div(vm);
			break;
		case IN_LDC:
			load_ldc(vm);
			break;
		default:
			break;
	}
	vm_stackdump(vm);
}
