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
 */
void m_exit(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * op_exit - exit the program with an error message on
 * opcode/operation related errors
 * @n: exit signals
 * @opcode: operation code
 * @ln: line NUMBER
 */
void op_exit(int n, char *opcode, int ln)
{
	(void)n;
	(void)opcode;
	(void)ln;
}
