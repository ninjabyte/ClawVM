#include <stdio.h>
#include <stdint.h>
#include "error.h"

/* error messages */
const char* error_messages[] =
{
	"No errors occurred",
	"Invalid file",
	"Unimplemented instruction",

	/* Runtime errors */
	"Divide by zero",
	"Variable is of invalid type",
	"Variable is invalid or does not exist",
	"Jump out of bounds"
};

/* prints the error message of an error code */
void error_printmsg(uint8_t code)
{
	if (code < NUM_ERRORS && code > ERR_NO_ERROR)
		fprintf(stderr, "Error: %s\n", error_messages[code]);
}
