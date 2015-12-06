#include "load.h"
#include "../vm.h"
#include "../var/object.h"
#include "../var/number.h"
#include "../mem/ClawStack.h"
#include "../error/error.h"

/* Load a constant to the stack */
void load_ldc(VMState* vm)
{
	Claw_Object object;
	object.type = TYPE_NUMBER;
	object.data_number = (Claw_Number) (vm_fetch(vm) << 8 | vm_fetch(vm));
	stack_push(&vm->stack, &object);
}
