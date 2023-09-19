#include "monty.h"
/**
 * add - Add the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "add" opcode appears.
 *
 * Description: This function adds the top two elements of the stack.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp;

	/* Check if there are at least two elements on the stack */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Calculate the sum of the top two elements */
	sum = (*stack)->n + (*stack)->next->n;

	/* Remove the top element (the second element becomes the new top) */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	/* Update the new top element with the sum */
	(*stack)->n = sum;

	/* Free the memory of the removed top element */
	free(temp);
}

/**
 * pint - Print the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "pint" opcode appears.
 *
 * Description: This function prints the value at the top of the stack.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the value at the top of the stack */
	printf("%d\n", (*stack)->n);
}

/**
 * nop - Do nothing.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "nop" opcode appears.
 *
 * Description: This function does nothing and is used as a placeholder opcode.
 * It's a no-operation (nop).
 */
void nop(stack_t **stack, unsigned int line_number)
{
	/* Suppress unused parameter warnings */
	(void)stack;
	(void)line_number;
	/* This function does nothing, as it's a placeholder for a no-op */
}

/**
 * _integer - Check if a string contains an integer.
 * @str: The string to check.
 * Return: 0 if the string contains an integer, otherwise 1.
 */
int _integer(const char *str)
{
	if (!str || !*str || (*str != '-' && !isdigit(*str)))
		return (0);
		
	int i;

	for (i = 1; str[i]; i++)
	{
		if (isdigit(str[i]))
			return (0);
	}
	return (1);
}
