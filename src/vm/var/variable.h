#ifndef OBJECT_H_
#define OBJECT_H_

#include "array.h"
#include "number.h"

#define TYPE_NUMBER 0
#define TYPE_ARRAY 1

Claw_Number;
Claw_Array;

typedef struct {
	uint8_t type;
	union {
		Claw_Number data_number;
		Claw_Array data_array;
	};
} Claw_Data;

#endif /* OBJECT_H_ */
