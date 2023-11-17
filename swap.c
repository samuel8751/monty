#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the beginning of the stack.
 * @line_number: Line number of the current operation.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

