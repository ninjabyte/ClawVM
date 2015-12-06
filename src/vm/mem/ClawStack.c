#include <malloc.h>
#include <string.h>
#include "ClawStack.h"
#include "../var/object.h"

/* create a new stack */
int stack_create(ClawStack_t* stack, size_t capacity)
{
	stack->capacity = capacity;
	stack->top = 0;
	stack->data = (Claw_Object*) malloc(stack->capacity * sizeof(Claw_Object));
	return stack->data == 0;
}

/* destroy a stack */
void stack_destroy(ClawStack_t* stack)
{
	if (stack->data)
		free(stack->data);
	stack->capacity = 0;
	stack->top = 0;
}

/* copy item and lay it on the stack */
int stack_push(ClawStack_t* stack, Claw_Object* item)
{
	while (stack->top >= stack->capacity)
	{
		stack->capacity++;
		if (stack->capacity >= STACK_MAX_CAP)
		{
			stack_destroy(stack);
			return 1;
		}

		stack->data = (Claw_Object*) realloc(stack->data, stack->capacity * sizeof(Claw_Object));
		if (!stack->data)
			return 2;
	}

	stack->data[stack->top++] = *item;
	return 0;
}

/* pop item and return the pointer to it. Lives until another item is pushed */
void* stack_pop(ClawStack_t* stack)
{
	stack->top--;
	if (stack->top < 0 || stack->top >= STACK_MAX_CAP) /* in case size_t is unsigned*/
		return NULL;
	return &stack->data[stack->top];
}
