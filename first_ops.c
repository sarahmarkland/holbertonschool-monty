#include "monty.h"

/**
 * pall - prints all values in a stack
 * @stack: linked list stack to print
 * @line_number: current line number of bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = *stack;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
	(void) line_number;
}

/**
 * pint - prints the value in the first node of a stack
 * @stack: linked list stack to pint
 * @line_number: current line number of bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		close_error();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * nop - does nothing
 * @stack: linked list stack to do nothing to
 * @line_number: current line number of bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
