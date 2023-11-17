#include "monty.h"
#include <ctype.h>

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 1;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        char *opcode, *arg;
        opcode = strtok(line, " \t\n");
        if (opcode != NULL && opcode[0] != '#')
        {
            arg = strtok(NULL, " \t\n");
            if (arg != NULL && (isdigit(*arg) == 0 && *arg != '-'))
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free(line);
                fclose(file);
                exit(EXIT_FAILURE);
            }

            execute_opcode(&stack, opcode, arg, line_number);
        }
        line_number++;
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return EXIT_SUCCESS;
}

