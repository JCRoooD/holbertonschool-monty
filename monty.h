#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/* Structs */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global Variable */
extern stack_t *top;

/* Function Prototypes */
void push(stack_t **stack, unsigned int line_number, char *line);
void pall(stack_t **stack, unsigned int line_number, char *line);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
void monty_error(const char **message, unsigned int line_number);
void memory_error();
void exit_failure(const char **message);
void (*get_op_func(char **opcode))(stack_t **, unsigned int);
void execute_instruction(stack_t **stack, char *line, unsigned int line_number);
void execute_instruction(stack_t **stack, instruction_t **instr, unsigned int line_number);
instruction_t *get_op_func(char *opcode);



#endif /* MONTY_H */

