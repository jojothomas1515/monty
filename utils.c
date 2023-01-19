#include "monty.h"

/**
 * parse_and_exec - parse and tokeninize the string and execute
 * @line: target string
 * @line_num: line number
 * @stack: to work on
 * Return: nothing
 */

void parse_and_exec(char *line, int line_num, stack_t **stack)
{
	char *tok;
	char *tok2;

	if (line == NULL)
		goto end_of;
	tok = strtok(line, "\n");
	if (tok == NULL)
		goto end_of;
	tok = strtok(tok, " ");
	if (tok == NULL)
		goto end_of;
	if (tok[0] == '#')
		goto end_of;

	if (get_opcode_func(tok) == NULL)
		op_exit(-2, tok, line_num, *stack);

	tok2 = strtok(NULL, " ");
	value = tok2 == NULL ? LONG_MIN : (long)atoi(tok2);
	get_opcode_func(tok)(stack, line_num);
end_of:
	if (tok)
		(void)NULL;
}

/**
 * get_opcode_func - get the opcode funtction specified by the tok
 * @tok: opcode string
 * Return: function on success or NULL on failure
 */

void (*get_opcode_func(char *tok))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {{"push", push_stack},
			       {"pall", pall_stack},
			       {"pop", pop_stack},
			       {"pint", pint_stack},
			       {"swap", swap_stack},
			       {"add", add_stack},
			       {"nop", nop_stack},
			       {"sub", sub_stack},
			       {"div", div_stack},
			       {"mul", mul_stack},
			       {"mod", mod_stack},
			       {NULL, NULL}};
	int i;

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(ops[i].opcode, tok) == 0)
			return (ops[i].f);
	}
	return (NULL);
}

/**
 * free_stack - free the linked list
 * @stack: target stack
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
