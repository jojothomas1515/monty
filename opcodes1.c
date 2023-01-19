#include "monty.h"

/**
 * nop_stack - nop does nothing
 * @stack: target stack
 * @line_number: line number
 */
void nop_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add_stack - add the two topmost item on the stack
 * @stack: target stack
 * @line_number: line number
 */
void add_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = NULL;

	if (stack == NULL || (*stack) == NULL)
		op_exit(-6, NULL, line_number, NULL);
	cn = (*stack);
	if (cn->next == NULL)
		op_exit(-6, NULL, line_number, NULL);

	cn->next->n = cn->next->n + cn->n;
	pop_stack(stack, line_number);
}
