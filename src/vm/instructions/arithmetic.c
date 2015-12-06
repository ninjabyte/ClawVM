#include "arithmetic.h"
#include "../vm.h"
#include "../var/object.h"
#include "../mem/ClawStack.h"
#include "../error/error.h"

int getNumNum(VMState* vm, Claw_Object** op0, Claw_Object** op1);

int getNumNum(VMState* vm, Claw_Object** op0, Claw_Object** op1)
{
	*op0 = stack_pop(&vm->stack);
	*op1 = stack_pop(&vm->stack);

	if (*op0 == NULL || *op1 == NULL)
	{
		vm_error(vm, ERR_INVALID_TYPE);
		return 1;
	}

	if ((*op0)->type != TYPE_NUMBER || (*op1)->type != TYPE_NUMBER)
	{
		vm_error(vm, ERR_INVALID_TYPE);
		return 2;
	}

	return 0;
}

/* add the 2 topmost values */
void aritmetic_add(VMState* vm)
{
	Claw_Object* op0 = NULL;
	Claw_Object* op1 = NULL;
	if (getNumNum(vm, &op0, &op1) != 0)
		return;
	Claw_Object object;
	object.type = TYPE_NUMBER;
	object.data_number = (Claw_Number) (op1->data_number + op0->data_number);
	stack_push(&vm->stack, &object);
}

/* subtract the 2 topmost values */
void aritmetic_sub(VMState* vm)
{
	Claw_Object* op0 = NULL;
	Claw_Object* op1 = NULL;
	if (getNumNum(vm, &op0, &op1) != 0)
		return;
	Claw_Object object;
	object.type = TYPE_NUMBER;
	object.data_number = (Claw_Number) (op1->data_number - op0->data_number);
	stack_push(&vm->stack, &object);
}

/* multiply the 2 topmost values */
void aritmetic_mul(VMState* vm)
{
	Claw_Object* op0 = NULL;
	Claw_Object* op1 = NULL;
	if (getNumNum(vm, &op0, &op1) != 0)
		return;
	Claw_Object object;
	object.type = TYPE_NUMBER;
	object.data_number = (Claw_Number) (op1->data_number * op0->data_number);
	stack_push(&vm->stack, &object);
}

/* divide the 2 topmost values */
void aritmetic_div(VMState* vm)
{
	Claw_Object* op0 = NULL;
	Claw_Object* op1 = NULL;
	if (getNumNum(vm, &op0, &op1) != 0)
		return;
	else if (op0->data_number == 0)
	{
		vm_error(vm, ERR_DIVIDE_BY_ZERO);
		return;
	}
	Claw_Object object;
	object.type = TYPE_NUMBER;
	object.data_number = (Claw_Number) (op1->data_number / op0->data_number);
	stack_push(&vm->stack, &object);
}
