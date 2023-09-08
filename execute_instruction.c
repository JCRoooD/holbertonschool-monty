#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * get_op_func - Selects the appropriate function to perform
 *               the operation specified by `opcode`.
 * @opcode: The Monty ByteCode operation to perform
 *
 * Return: A function pointer to the corresponding operation, or NULL
 *         if the operation is not recognized.
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };
    int i = 0;

    while (ops[i].opcode)
    {
        if (strcmp(ops[i].opcode, opcode) == 0)
            return (ops[i].f);
        i++;
    }
    return (NULL);
}

/**
 * execute_instruction - Executes a Monty ByteCode instruction.
 * @stack: Pointer to the head of the stack
 * @line: The Monty ByteCode instruction to execute
 * @line_number: Line number being executed from Monty file
 */
void execute_instruction(stack_t **stack, char *line, unsigned int line_number)
{
    char *opcode;
    void (*func)(stack_t **, unsigned int);

    opcode = strtok(line, " \t\n");
    if (!opcode)
        return;

    func = get_op_func(opcode);
    if (func)
        func(stack, line_number);
    else
        monty_error("unknown instruction", line_number);
}
