#include "monty.h"

/**
 * push_stack - push an item on top the stack
 * @stack: target stack
 * @line_number: line number
 * Return: nothing
 */

void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *nn = NULL;

	(void)line_number;
	if (stack == NULL)
		m_exit(*stack);

	nn = malloc(sizeof(stack_t));
	if (nn == NULL)
		m_exit(*stack);

	if (val.n == NULL)
		op_exit(-1, NULL, line_number, *stack);
	if (atoi_check(val.n) == 0)
		op_exit(-1, NULL, line_number, *stack);
	nn->n = atoi(val.n);
	nn->next = NULL;
	nn->prev = NULL;

	if ((*stack) == NULL)
	{
		(*stack) = nn;
		val.tail = *stack;
		goto end_of;
	}

	if (strcmp(val.mode, "queue") == 0)
	{
		val.tail->next = nn;
		nn->prev = val.tail;
		val.tail = nn;
	}
	else
	{
		nn->next = (*stack);
		(*stack)->prev = nn;
		(*stack) = nn;
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
		printf("%d\n", cn->n);
		cn = cn->next;
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
	stack_t *cn = NULL, *temp = NULL;

	if (stack == NULL)
		op_exit(-4, NULL, line_number, NULL);
	cn = (*stack);
	if ((*stack) == NULL)
		op_exit(-4, NULL, line_number, NULL);

	if (cn->next == NULL)
		val.tail = NULL;
	if (cn->next)
	{
		temp = cn->next;
		temp->prev = NULL;
	}
	(*stack) = temp;

	free(cn);
}

/**
 * pint_stack - print the value at the top of the stack
 * @stack: target stack
 * @line_number: line number
 */

void pint_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack == NULL)
		op_exit(-3, NULL, line_number, NULL);
	if ((*stack) == NULL)
		op_exit(-3, NULL, line_number, NULL);

	printf("%d\n", (*stack)->n);
}

/**
 * swap_stack - swap the two topmost item on the stack
 * @stack: target stack
 * @line_number: line number
 */
void swap_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *cn = NULL, *temp = NULL;

	if (stack == NULL || (*stack) == NULL)
		op_exit(-5, NULL, line_number, NULL);
	cn = (*stack);
	if (cn->next == NULL)
		op_exit(-5, NULL, line_number, NULL);

	temp = cn->next;
	cn->next = temp->next;
	cn->prev = temp;
	temp->next = cn;
	temp->prev = NULL;
	*stack = temp;
}
