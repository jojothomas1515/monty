#include "monty.h"

/**
 * main - entry point for my program
 * @argc: arguments count
 * @argv: arguments array of strings
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *monty;
	char rbuff[100];
	char *filename;

	if (argc != 1)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	monty = fopen(filename, "r");
	if (monty == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(rbuff, 100, monty))
	{
		parse_and_exec(rbuff);
	}

	fclose(monty);
	return (0);
}
