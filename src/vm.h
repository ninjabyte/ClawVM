#ifndef VM_H_
#define VM_H_

#include <stdio.h>
#include <stdint.h>
#include "types.h"
#include "vmstate.h"

void vm_init(VMState*, FILE*);
int vm_run(VMState*);
void vm_executeNext(VMState*, Instruction);

#endif /* VM_H_ */
