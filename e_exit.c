#include "monty.h"

/**
 * f_exit - exit the program with an error message
 * @n: exit signal
 * @filename: the file name for detailed error
 */
void f_exit(int n, char *filename)
{
	switch (n)
	{
	case -1:
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
		break;
	case -2:
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
		break;
	default:
		exit(EXIT_FAILURE);
		break;
	}
}

/**
 * m_exit - exit the program with an error message on malloc related errors
 * @stack: target stack
 */
void m_exit(stack_t *stack)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * op_exit - exit the program with an error message on
 * opcode/operation related errors
 * @n: exit signals
 * @opcode: operation code
 * @ln: line NUMBER
 * @stack: target stack
 */
void op_exit(int n, char *opcode, int ln, stack_t *stack)
{
	switch (n)
	{
	case -1:
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
		break;
	case -2:
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
		free_stack(stack);
		exit(EXIT_FAILURE);
		break;
	case -3:
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
		break;
	case -4:
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
		break;
	case -5:
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
		break;

	default:
		break;
	}
}
