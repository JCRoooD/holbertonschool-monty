#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/* Function to print an error message and exit with failure status */
void monty_error(const char *message, unsigned int line_number)
{
	fprintf(stderr, "L%d: %s\n", line_number, message);
	exit(EXIT_FAILURE);
}

/* Function to handle memory allocation errors */
void memory_error()
{
	fprintf(stderr, "Error: Memory allocation failed\n");
	exit(EXIT_FAILURE);
}
