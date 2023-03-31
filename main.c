#include "monty.h"
/**
 * main - entry function for Monty, the baby python
 * @argc: number of command line args passed
 * @argv: ptr to ptr to array of strings containing args
 * Return: Always 0 (on Success), 1 on failure
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *file = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		tokentime(line, " \n\t", &stack);
		op_fun_res(&stack, opcodes);
	}
	{
		free(line);
		fclose(file);
		free_stack(&stack, NULL);
	}
	return (0);
}
