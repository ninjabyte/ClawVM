#include <stdio.h>
#include "vm.h"
#include "instruction.h"
#include "error/error.h"

/* initialize a virtual machine */
void vm_init(VMState* vm, FILE* code)
{
	vm->File = code;
	vm->IsRunning = 0;
	vm->Error = ERR_NO_ERROR;
}

/* run the virtual machine */
int vm_run(VMState* vm)
{
	int instr;
	while (vm->Error == ERR_NO_ERROR && vm->IsRunning && (instr = fgetc(vm->File)) != EOF) {
		vm_executeNext(vm, (instr_t) instr);
	}

	return vm->Error;
}

/* execute the next instrution */
void vm_executeNext(VMState* vm, instr_t instr)
{
	switch(instr)
	{
		case IN_NOP:
			break;
		case IN_HCF:
			vm->Error = ERR_ON_FIRE;
			break;
	}
}
