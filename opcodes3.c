#include "monty.h"

/**
 * set_stack - set the push system to stack format
 * @stack: target stack
 * @line_number: line number
 */
void set_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	val.mode = "stack";
}

/**
 * set_queue - set the push system to stack format
 * @stack: target stack
 * @line_number: line number
 */
void set_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	val.mode = "queue";
}
