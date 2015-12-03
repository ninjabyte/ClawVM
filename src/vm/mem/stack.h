#ifndef STACK_H_
#define STACK_H_

#ifndef STACK_MAX_CAP
#define STACK_MAX_CAP 512
#endif

#include <string.h>

typedef struct {
	void** data;
	size_t capacity;
	size_t top;
} stack_t;

int stack_create(stack_t* stack, size_t capacity);
void stack_destroy(stack_t* stack);
int stack_push(stack_t* stack, void* item);
void* stack_pop(stack_t* stack);

#endif /* STACK_H_ */
