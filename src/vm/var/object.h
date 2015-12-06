#ifndef OBJECT_H_
#define OBJECT_H_

#include "array.h"
#include "number.h"
#include "variable.h"

#define TYPE_NUMBER 0
#define TYPE_ARRAY 1
#define TYPE_VARIABLE 2

typedef struct {
	uint8_t type;
	union {
		Claw_Number data_number;
		Claw_Array data_array;
		Claw_Variable data_variable;
	};
} Claw_Object;

#endif /* OBJECT_H_ */
