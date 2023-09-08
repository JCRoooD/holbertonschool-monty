#include "monty.h"
/**
 * main - Entry Point
 * @argc: argument counter
 * @argv: argument vector
 * Return: exit the program
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file");
            exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r"); /*open file read only*/
    if (file == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        execute_instruction(&stack, line, line_number);
    }
    fclose(file);
    free_stack(stack);

    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}

#include "monty.h"

/**
 * free_stack - Free the memory allocated for the stack and its nodes.
 * @stack: Pointer to the stack.
 *
 * Description: This function frees the memory allocated for the stack and
 * its nodes, ensuring there are no memory leaks.
 */
void free_stack(stack_t *stack)
{
    stack_t *current;

    while (stack != NULL)
    {
        current = stack;
        stack = stack->next;
        free(current);
    }
}
