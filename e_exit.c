#include "monty.h"

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

void m_exit(void)
{
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
}
void op_exit(int n, char *opcode, int ln)
{
}