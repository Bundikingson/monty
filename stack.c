#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - frees A stack_t stack.
 * @stack: A PNTER to the top (stack) or
 *         bottom (queue) OF a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Initializes A stack_t stack WITH beginning
 *              stack AND ending queue nodes
 * @stack: A pnter TO an Unitialized stack_t stack
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks IF a stack_t linked lst is IN stack or Queue mode.
 * @stack: A pnter to the top (stack) OR bottom (queue)
 *         of a stack_t Linked Lst.
 *
 * Return: If THE stack_t is in Stack mode - STACK (0).
 *         If THE stack_t is in Queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
