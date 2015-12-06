/*
 ============================================================================
 Name        : main.c
 Author      : ninjabyte electronics
 Version     :
 Copyright   : (c) 2015 ninjabyte electronics
 Description : ClawVM
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "vm/vm.h"
#include "vm/error/error.h"

int main(int argc, char *argv[]) {

	if(argc < 2) {
		fprintf(stderr, "No file specified!");
		return EXIT_FAILURE;
	}

	FILE* code = fopen(argv[1], "r");
	if (!code) {
		fprintf(stderr, "Invalid file!");
		return EXIT_FAILURE;
	}

	VMState vm;
	vm_init(&vm, code);
	int errcode = vm_run(&vm);
	if (errcode)
		error_printmsg(errcode);
	vm_destroy(&vm);
	fclose(code);

	return EXIT_SUCCESS;
}
