#ifndef VM_H_
#define VM_H_

#include <stdio.h>
#include <stdint.h>
#include "types.h"

void vm_init(VMState* vm, FILE* code);
int vm_run(VMState* vm);
void vm_executeNext(VMState* vm);

#endif /* VM_H_ */
