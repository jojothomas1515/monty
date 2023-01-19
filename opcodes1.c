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

/**
 * sub_stack - sub the two topmost item on the stack
 * @stack: target stack
 * @line_number: line number
 */
void sub_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = NULL;

	if (stack == NULL || (*stack) == NULL)
		op_exit(-7, NULL, line_number, NULL);
	cn = (*stack);
	if (cn->next == NULL)
		op_exit(-7, NULL, line_number, NULL);

	cn->next->n = cn->next->n - cn->n;
	pop_stack(stack, line_number);
}

/**
 * div_stack - div the two topmost item on the stack
 * @stack: target stack
 * @line_number: line number
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = NULL;

	if (stack == NULL || (*stack) == NULL)
		op_exit2(-8, NULL, line_number, NULL);
	cn = (*stack);
	if (cn->next == NULL)
		op_exit2(-8, NULL, line_number, NULL);

	if (cn->n == 0)
		op_exit2(-9, NULL, line_number, NULL);

	cn->next->n = cn->next->n / cn->n;
	pop_stack(stack, line_number);
}

/**
 * mul_stack - mul the two topmost item on the stack
 * @stack: target stack
 * @line_number: line number
 */
void mul_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = NULL;

	if (stack == NULL || (*stack) == NULL)
		op_exit2(-10, NULL, line_number, NULL);
	cn = (*stack);
	if (cn->next == NULL)
		op_exit2(-10, NULL, line_number, NULL);

	cn->next->n = cn->next->n * cn->n;
	pop_stack(stack, line_number);
}
