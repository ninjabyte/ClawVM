#include <stdio.h>
#include "vm.h"
#include "instruction.h"
#include "error/error.h"

/* initialize a virtual machine */
void vm_init(VMState* vm, FILE* code)
{
	vm->code = code;
	vm->running = 0;
	vm->error = ERR_NO_ERROR;
}

/* run the virtual machine */
int vm_run(VMState* vm)
{
	int instr;
	while (vm->error == ERR_NO_ERROR && vm->running && (instr = fgetc(vm->code)) != EOF) {
		vm_executeNext(vm, (instr_t) instr);
	}

	return vm->error;
}

/* execute the next instrution */
void vm_executeNext(VMState* vm, instr_t instr)
{
	switch(instr)
	{
		case IN_NOP:
			break;
		case IN_HCF:
			vm->error = ERR_ON_FIRE;
			break;
	}
}
