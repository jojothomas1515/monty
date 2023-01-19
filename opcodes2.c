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
