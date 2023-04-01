#include "monty.h"

/**
 * free_stack - free memory allocated for stack
 * @stack: ptr to stack (linked list)
 * Return: void
 */

void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
