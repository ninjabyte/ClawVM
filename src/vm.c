#include <stdio.h>
#include "vm.h"
#include "bc/bytecode.h"
#include "error/error.h"

/* initialize a virtual machine */
void vm_init(VMState* vm, FILE* file)
{
	vm->File = file;
	vm->IsRunning = 0;
	vm->Error = ERR_NO_ERROR;
}

/* run the virtual machine */
int vm_run(VMState* vm)
{
	int instr;
	while (vm->Error == ERR_NO_ERROR && vm->IsRunning && (instr = fgetc(vm->File)) != EOF) {
		vm_executeNext(vm, (Instruction)instr);
	}

	return vm->Error;
}

/* execute the next instruction */
void vm_executeNext(VMState* vm, Instruction instr)
{
	switch(instr) {
		case IN_NOP:
			break;
		case IN_HCF:
			vm->Error = ERR_ON_FIRE;
			break;
		default:

	}
}
