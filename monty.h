#ifndef MONTY_H
#define MONTY_H

/* prototype declaration */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* structures and typedef */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * mvalue - structure for my global variables
 * @n: stack value
 * @tail: tail node of the stack
 */
typedef struct mvalue
{
	char *n;
	char *mode;
	stack_t *tail;

} mval;

/* prototype declaration and utilities*/
void parse_and_exec(char *, int, stack_t **);
void (*get_opcode_func(char *tok))(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int atoi_check(char *num_tok);

/* stacks prototypes */
void pall_stack(stack_t **stack, unsigned int line_number);
void push_stack(stack_t **stack, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
void pint_stack(stack_t **stack, unsigned int line_number);
void swap_stack(stack_t **stack, unsigned int line_number);
void add_stack(stack_t **stack, unsigned int line_number);
void nop_stack(stack_t **stack, unsigned int line_number);
void sub_stack(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mul_stack(stack_t **stack, unsigned int line_number);
void mod_stack(stack_t **stack, unsigned int line_number);
void pchar_stack(stack_t **stack, unsigned int line_number);
void pstr_stack(stack_t **stack, unsigned int line_number);
void rotl_stack(stack_t **stack, unsigned int line_number);
void rotr_stack(stack_t **stack, unsigned int line_number);
void set_stack(stack_t **stack, unsigned int line_number);
void set_queue(stack_t **stack, unsigned int line_number);

/* exit prototypes */
void f_exit(int, char *);
void m_exit(stack_t *);
void op_exit(int n, char *opcode, int ln, stack_t *);
void op_exit2(int n, char *opcode, int ln, stack_t *);

/* global variables */
extern mval val;

#endif /* MONTY_H */
