#include "monty.h"
/**
 * execute_instruction - Execute Monty ByteCode instruction.
 * @stack: Pointer to the stack.
 * @line: The instruction line.
 * @line_number: The line number in the Monty file.
 *
 * Description: This function parses and executes Monty ByteCode instructions
 * using an array of instruction_t structures.
 */
void execute_instruction(stack_t **stack, char *line, unsigned int line_number)
{
    char *opcode, *argument;
    unsigned int value;

    opcode = strtok(line, " \t\n");
    if (opcode == NULL)
        return;

    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"pint", pint},
        {"nop", nop},
        {NULL, NULL}
    };

    for (int i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            if (strcmp(opcode, "push") == 0)
            {
                argument = strtok(NULL, " \t\n");
                if (argument == NULL)
                {
                    fprintf(stderr, "L%u: usage push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }
                value = atoi(argument);
                instructions[i].f(stack, value);
            }
            else
            {
                instructions[i].f(stack, line_number);
            }
            return;
        }
    }
    fprintf(stderr, "L%u: unknown instructions %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
