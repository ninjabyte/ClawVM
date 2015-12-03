#include <malloc.h>
#include <string.h>
#include "stack.h"

int stack_create(stack_t* stack, size_t capacity)
{
	stack->capacity = capacity;
	stack->top = 0;
	stack->data = (void**) malloc(stack->capacity * sizeof(void*));
	return stack->data == 0;
}

void stack_destroy(stack_t* stack)
{
	if (stack->data)
		free(stack->data);
	stack->capacity = 0;
	stack->top = 0;
}

int stack_push(stack_t* stack, void* item)
{
	while (stack->top >= stack->capacity)
	{
		stack->capacity++;
		if (stack->capacity >= STACK_MAX_CAP)
		{
			stack_destroy(stack);
			return 1;
		}

		stack->data = (void**) realloc(stack->data, stack->capacity * sizeof(void*));
		if (!stack->data)
			return 2;
	}

	stack->data[stack->top++] = item;
	return 0;
}

void* stack_pop(stack_t* stack)
{
	stack->top--;
	if (stack->top < 0 || stack->top >= STACK_MAX_CAP) /* in case size_t is unsigned*/
		return NULL;
	return stack->data[stack->top];
}
