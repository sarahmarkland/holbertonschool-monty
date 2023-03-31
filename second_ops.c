#include "monty.h"

/**
 * push - pushes a new node to the top of a stack
 * @stack: linked list stack to push to
 * @line_number: current line number of bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
	}
}
