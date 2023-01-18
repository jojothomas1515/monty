#include "monty.h"

/**
 * parse_and_exec - parse and tokeninize the string and execute
 * @line: target string
 * Return: nothing
 */

void parse_and_exec(char *line, int line_num)
{
	char *tok;

	if (line == NULL)
		return;
	if ((tok = strtok(line, "\n")) == NULL)
		return;
	if ((tok = strtok(tok, " ")) == NULL)
		return;

	if (get_opcode_func(tok) == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s", line_num, tok);
		exit(EXIT_FAILURE);
	}

	get_opcode_func(tok)(head, line_num);
	free(tok);
	return;
}


void (*get_opcode_func(char *tok))(stack_t **stack, unsigned int line_number);
{
	instruction_t ops[] ={{"push", push_stack},
			      {"pall", pall_stack},
			      {"pop", pop_stack},
			      {"pint", pint_stack},
			      {NULL, NULL}};
	int i;

	for (i = 0, i < 4; i++}
	{
		if (strcmp(ops[i]->opcode, tok) == 0)
			return (ops[i].f);
	}
	return (NULL);
}
