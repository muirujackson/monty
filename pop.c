#include "monty.h"

/**
 * pop - push value
 * @stack: pointer to a pointer
 * @line_number: number
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	
	stack_t *temp = *stack;
	
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
