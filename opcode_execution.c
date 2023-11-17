#include "monty.h"

/**
 * execute_opcode - Executes the specified opcode.
 * @stack: Pointer to the beginning of the stack.
 * @opcode: The opcode to execute.
 * @arg: The argument for the opcode.
 * @line_number: Line number of the current operation.
 */
void execute_opcode(stack_t **stack, char *opcode, char *arg, unsigned int line_number)
{
    if (strcmp(opcode, "push") == 0)
    {
        if (arg == NULL || (!isdigit(*arg) && *arg != '-'))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        push(stack, atoi(arg));
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }

    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

