#ifndef STACK_H_
#define STACK_H_

#ifndef STACK_MAX_CAP
#define STACK_MAX_CAP 512
#endif

#include <string.h>
#include "../var/object.h"

typedef struct {
	Claw_Object* data;
	size_t capacity;
	size_t top;
} ClawStack_t;

int stack_create(ClawStack_t* stack, size_t capacity);
void stack_destroy(ClawStack_t* stack);
int stack_push(ClawStack_t* stack, Claw_Object* item);
void* stack_pop(ClawStack_t* stack);

#endif /* STACK_H_ */
