#include "monty.h"

long int value = 0;

/**
 * main - entry point for my program
 * @argc: arguments count
 * @argv: arguments array of strings
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int line_number = 1;
	FILE *monty;
	char rbuff[100];
	char *filename;
	stack_t *stack = NULL;

	if (argc != 2)
		f_exit(-1, NULL);

	filename = argv[1];
	monty = fopen(filename, "r");
	if (monty == NULL)
		f_exit(-2, filename);

	while (fgets(rbuff, 100, monty))
	{
		parse_and_exec(rbuff, line_number, &stack);
		line_number++;
	}

	fclose(monty);
	free_stack(stack);
	return (0);
}
