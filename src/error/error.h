#ifndef ERROR_H_
#define ERROR_H_

/* error code enum */
enum Error
{
	ERR_NO_ERROR,
	ERR_INVALID_FILE,
	ERR_ON_FIRE,
	ERR_UNIMPLEMENTED_INSTR,

	/* Runtime errors */
	ERR_DIVIDE_BY_ZERO,
	ERR_ARRAY_OUT_OF_BOUNDS,
	ERR_INVALID_TYPE,
	ERR_INVALID_VAR,
	ERR_JUMP_OUT_OF_BOUNDS,

	NUM_ERRORS
};

void error_printmsg(int code);
void error_printmsgln(int code, int line);

#endif /* ERROR_H_ */
