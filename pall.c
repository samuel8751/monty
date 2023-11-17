#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the beginning of the stack.
 * @line_number: Line number of the current operation.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

