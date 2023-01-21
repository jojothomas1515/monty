#include "monty.h"

/**
 * mod_stack - mod the two topmost item on the stack
 * @stack: target stack
 * @line_number: line number
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = NULL;

	if (stack == NULL || (*stack) == NULL)
		op_exit2(-11, NULL, line_number, NULL);
	cn = (*stack);
	if (cn->next == NULL)
		op_exit2(-11, NULL, line_number, NULL);

	if (cn->n == 0)
		op_exit2(-9, NULL, line_number, NULL);

	cn->next->n = cn->next->n % cn->n;
	pop_stack(stack, line_number);
}

/**
 * pchar_stack - print the char of the top stack
 * @stack: target stack
 * @line_number: line number
 */

void pchar_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = *stack;

	if (stack == NULL || (*stack) == NULL)
		op_exit2(-13, NULL, line_number, NULL);

	if (cn->n < 1 || cn->n > 127)
		op_exit2(-12, NULL, line_number, NULL);

	printf("%c\n", (char)cn->n);
}
/**
 * pstr_stack - pr prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: target stack
 * @line_number: line number
 */

void pstr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = *stack;

	(void)line_number;
	if (!(stack == NULL || (*stack) == NULL))
		for (; cn; cn = cn->next)
		{
			if (cn->n < 1 || cn->n > 127)
				break;
			printf("%c", (char)cn->n);
		}
	printf("\n");
}
