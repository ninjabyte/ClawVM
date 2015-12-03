#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdint.h>
#include "../mem/stack.h"

typedef struct
{
	uint8_t type;
} object_t;

/* For creating new object types */
typedef struct {
	void* (*initialize)(stack_t* vmstack);
	void* (*finalize)();
} ObjectHandle_t;

#endif /* OBJECT_H_ */
