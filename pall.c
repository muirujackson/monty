#include "monty.h"


/**
 * pall - push value
 * @stack: pointer to a pointer
 * @line_number: number
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}
