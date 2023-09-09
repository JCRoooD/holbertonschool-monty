#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number being executed from Monty file
 * @line: The Monty ByteCode instruction line (unused here)
 */
void push(stack_t **stack, unsigned int line_number, char *line)
{
	stack_t *new_node;
	int value;

	if (!stack || !line)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (sscanf(line, "%d", &value) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;

	(void)line; /*Marking the parameter as unused to avoid a warning*/
}

/**
 * pall - Prints all the values in the stack, starting from the top.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number being executed from Monty file
 * @line: The Monty ByteCode instruction line (unused here)
 */
void pall(stack_t **stack, unsigned int line_number, char *line)
{
	stack_t *current = *stack;

	(void)line_number; /*Unused parameter*/
	(void)line;       /*Marking the parameter as unused to avoid a warning*/

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number being executed from Monty file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number being executed from Monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
