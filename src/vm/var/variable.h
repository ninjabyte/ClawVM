#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <stdint.h>

typedef struct {
	uint16_t id;
	void* value;
} Claw_Variable;

#endif /* VARIABLE_H_ */
