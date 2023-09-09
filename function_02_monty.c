#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number being executed from Monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number being executed from Monty file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number); /* You need to implement the pop function if it's not already implemented */
}

/**
 * nop - Does nothing (no-op).
 * @stack: Pointer to the head of the stack
 * @line_number: Line number being executed from Monty file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* No operation (nop) - Do nothing */
}

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

