#include "monty.h"

FILE *fd = NULL;
/**
 * main - entry function for Monty, the baby python
 * @argc: number of command line args passed
 * @argv: ptr to ptr to array of strings containing args
 * Return: Always 0 (on Success), 1 on failure
 */
int main(int argc, char **argv)
{
	void (*f)(stack_t **, unsigned int) = NULL;
	char *buffer = NULL, *token = NULL, *op = NULL, *n = NULL;
	size_t length = 0;
	stack_t *stack = NULL;
	const char deliminators[] = " \t\n";
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &length, fd) != -1)
	{
		token = strtok(buffer, deliminators);
		strcpy(op, token);
		f = get_func(&stack, line_number, token);
		if (strcmp(op, "push") == 0)
		{
			token = strtok(NULL, deliminators);
			if (token == NULL)
			{
				free(buffer), buffer = NULL, free_stack(&stack);
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
			}
			strcpy(n, token);
		}
		free(buffer), buffer = NULL, f(&stack, line_number);
		if (strcmp(op, "push") == 0)
			set_n(&stack, line_number, n);
	}
	free(buffer), buffer = NULL, free_stack(&stack);
	return (EXIT_SUCCESS);
}
/**
 * get_func - calls function matched to opcode
 * @stack: linked list
 * @l: line number
 * @code: opcode
 * Return: pointer to matched function
 */
void (*get_func(stack_t **stack, int l, char *code))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
/*		{"pop", pop},*/
/*		{"swap", swap},*/
/*		{"add", add},*/
		{"nop", nop}
	};

	while (strcmp(code, instructions[i].opcode) != 0)
	{
		i++;
		if (i > 7)
		{
			fprintf(stderr, "L%d: unknown instructions %s\n", l, code);
			free_stack(stack);
			close_error();
		}
	}
	return (instructions[i].f);
}

/**
 * set_n - sets the value of n
 * @stack: linked list
 * @line_num: current line number
 * @num: number to set n to
 */
void set_n(stack_t **stack, unsigned int line_num, char *num)
{
	if (strcmp(num, "0") == 0)
		(*stack)->n = 0;
	if (strcmp(num, "0") != 0)
	{
		(*stack)->n = atoi(num);
		if ((*stack)->n == 0 || (num[0] != '-' && (*stack)->n == 1))
		{
			fprintf(stderr, "Error: L%d: usage: push integer\n", line_num);
			free_stack(stack);
			close_error();
		}
	}
}

/**
 * close_error - closes file and exits with failure
 * Return: void
 */
void close_error(void)
{
	fclose(fd);
	exit(EXIT_FAILURE);
}
