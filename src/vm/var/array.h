#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdint.h>
#include <string.h>

typedef struct {
	uint8_t* data;
	size_t length;
} Claw_Array;

#endif /* ARRAY_H_ */
