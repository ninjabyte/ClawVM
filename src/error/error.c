#include <stdio.h>
#include "error.h"

/* error messages */
const char* error_messages[] =
{
	"No errors occurred",
	"Invalid file",
	"HELP Im on fire D:",
};

/* prints the error message of an error code */
void error_printmsg(int code)
{
	if (code < NUM_ERRORS && code > ERR_NO_ERROR)
		fprintf(stderr, "Error: %s\n", error_messages[code]);
}
