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
#include "vm.h"

int main(int argc, char *argv[]) {

	if(argc < 2) {
		fprintf(stderr, "No file specified!");
		return EXIT_FAILURE;
	}

	FILE* code = fopen(argv[1], "r");
	VMState vm;
	vm_init(&vm, code);
	vm_run(&vm);

	fclose(code);

	return EXIT_SUCCESS;
}
