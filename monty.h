#ifndef __MONTY_H__
#define __MONTY_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define DELIMS " \n\t\a\b"
#define STACK 0
#define QUEUE 1

/* GLOBAL opcode TOKENS */
extern char **op_toks;

/**
 * struct stack_s - DOUBLY LINKED LIST REPRESENTATION of a stack (or queue)
 * @n: INT..
 * @prev: POINTS to the PREVIOUS ELEMENT of the stack (or queue)
 * @next: POINTS to the NEXT ELEMENT of the stack (or queue)
 *
 * Description: DOUBLY LINKED LIST NODE structure..
 * for stack, queues, LIFO, FIFO HOLBERTON project..
 */
typedef struct stack_s

{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - OPCODE and its FUNCTION..
 * @opcode: the OPCODE..
 * @f: FUNCTION TO HANDLE the opcode..
 *
 * Description: opcode and ITS FUNCTION..
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s

{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY interpreter FUNCTIONS */

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);

/* OPCODE functions */

void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);

/* CUSTOM standard library FUNCTIONS */

char **strtow(char *str, char *delims);
char *get_int(int n);

/* ERROR MESSAGES & ERROR CODES */

int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);

#endif /* __MONTY_H__ */
