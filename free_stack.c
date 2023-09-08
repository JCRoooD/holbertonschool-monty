#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - Frees the entire stack.
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
    stack_t *current = stack;

    while (current)
    {
        stack_t *temp = current;
        current = current->next;
        free(temp);
    }
}

/**
 * exit_failure - Exits the program with a failure status.
 * @message: The error message to display
 */
void exit_failure(const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}
