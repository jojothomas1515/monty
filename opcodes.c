#include "monty.h"

/**
 * push_stack - push an item on top the stack
 * @stack: target stack
 * @line_number: line number
 * Return: nothing
 */

void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *nn = NULL, *cn = NULL;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	nn = malloc(sizeof(stack_t));
	if (nn == NULL)
		m_exit(*stack);

	if (value == INT_MIN)
		op_exit(-1, NULL, line_number, *stack);

	nn->n = value;
	nn->next = NULL;
	nn->prev = NULL;

	cn = (*stack);

	if ((*stack) == NULL)
	{
		(*stack) = nn;
		goto end_of;
	}

	while (cn)
	{
		if (cn->next == NULL)
		{
			cn->next = nn;
			nn->prev = cn;
			break;
		}
		cn = cn->next;
	}
end_of:
	(void)NULL;
}

/**
 * pall_stack - print all the items in the stack
 * @stack: target stack
 * @line_number: line number
 */

void pall_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = NULL;

	(void)line_number;

	if (stack == NULL)
		goto end_of;
	cn = (*stack);
	if ((*stack) == NULL)
		goto end_of;
	while (cn)
	{
		if (cn->next == NULL)

			break;

		cn = cn->next;
	}
	while (cn)
	{
		printf("%d\n", cn->n);
		cn = cn->prev;
	}

end_of:
	(void)NULL;
}

/**
 * pop_stack - print all the items in the stack
 * @stack: target stack
 * @line_number: line number
 */

void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = NULL;

	(void)line_number;

	if (stack == NULL)
		goto end_of;
	cn = (*stack);
	if ((*stack) == NULL)
		goto end_of;
	while (cn)
	{
		if (cn->next == NULL)

			break;

		cn = cn->next;
	}
	while (cn)
	{
		printf("%d\n", cn->n);
		cn = cn->prev;
	}

end_of:
	(void)NULL;
}

/**
 * pint_stack - print all the items in the stack
 * @stack: target stack
 * @line_number: line number
 */

void pint_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = NULL;

	(void)line_number;

	if (stack == NULL)
		goto end_of;
	cn = (*stack);
	if ((*stack) == NULL)
		goto end_of;
	while (cn)
	{
		if (cn->next == NULL)

			break;

		cn = cn->next;
	}
	while (cn)
	{
		printf("%d\n", cn->n);
		cn = cn->prev;
	}

end_of:
	(void)NULL;
}
