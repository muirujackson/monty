#include "monty.h"

/**
 * pint - push value
 * @stack: pointer to a pointer
 * @line_number: number
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
