#include "monty.h"
#include <string.h>
#include <stdio.h>  

void (*get_op_func(char *opcode))(stack_t**, unsigned int);
void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
int run_monty(FILE *script_fd);
 
/**
* free_tokens - FREES THE GLOBAL op_toks array of strings..
*/
void free_tokens(void)
 
{
size_t Z = 0;
 
if (op_toks == NULL)
return;
 
for (Z = 0; op_toks[Z]; Z++)
free(op_toks[Z]);
 
free(op_toks);
}
 
/**
* token_arr_len - Gets the length of current op_toks.
*
* Return: Length of current op_toks (as int).
*/
 
unsigned int token_arr_len(void)
 
{
unsigned int toks_len = 0;
 
while (op_toks[toks_len])
toks_len++;
return (toks_len);
}
 
/**
* is_empty_line - CHECKS IF A LINE read from getline only contains Delimiters.
* @line: A POINTER TO THE LINE..
* @delims: A string of delimiter CHAR..
*
* Return: If the line only contains delimiters - 1.
*         OTHERWISE - 0.
*/
 
int is_empty_line(char *line, char *delims)
 
{
int i, j;
 
for (i = 0; line[i]; i++)
{
for (j = 0; delims[j]; j++)
{
if (line[i] == delims[j])
break;
}
if (delims[j] == '\0')
return (0);
}
 
return (1);
}
 
/**
* get_op_func - Matches an OPCODE with its corresponding function.
* @opcode: The OPCODE TO MATCH..
*
* RETURN: A POINTER to the corresponding function..
*/
 
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
 
{
instruction_t op_funcs[] = {
{"push", monty_push},
{"pall", monty_pall},
{"pint", monty_pint},
{"pop", monty_pop},
{"swap", monty_swap},
{"add", monty_add},
{"nop", monty_nop},
{"sub", monty_sub},
{"div", monty_div},
{"mul", monty_mul},
{"mod", monty_mod},
{"pchar", monty_pchar},
{"pstr", monty_pstr},
{"rotl", monty_rotl},
{"rotr", monty_rotr},
{"stack", monty_stack},
{"queue", monty_queue},
{NULL, NULL}
};
int i;
 
for (i = 0; op_funcs[i].opcode; i++)
{
if (strcmp(opcode, op_funcs[i].opcode) == 0)
return (op_funcs[i].f);
}
 
return (NULL);
}
 
/**
* run_monty - PRIMARY FUNCTION to execute a Monty bytecodes script..
* @script_fd: FILE DESCRIPTOR for an open Monty bytecodes script..
*
* RETURN: EXIT_SUCCESS on success, respective error code on failure.
*/
 
int run_monty(FILE *script_fd)

{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t line_capacity = /* specify the buffer size */;
    size_t exit_status = EXIT_SUCCESS;
    unsigned int line_number = 0, prev_tok_len = 0;
    void (*op_func)(stack_t**, unsigned int);

    if (init_stack(&stack) == EXIT_FAILURE)
        return (EXIT_FAILURE);

    line = (char *)malloc(line_capacity);
    if (line == NULL) {
        /* Handle memory allocation failure */
    }

    size_t exit_status = EXIT_SUCCESS;
    unsigned int line_number = 0, prev_tok_len = 0;
    void (*op_func)(stack_t**, unsigned int);

    if (init_stack(&stack) == EXIT_FAILURE)
        return (EXIT_FAILURE);

 while (fgets(line, line_capacity, script_fd) != NULL)
    {
        line_number++;
        op_toks = strtow(line, DELIMS);
if (op_toks == NULL)
{
if (is_empty_line(line, DELIMS))
continue;
 free_stack(&stack);

    if (line && *line == 0)
    {
        free(line);
        return (malloc_error());
    }

    free(line);
    return (exit_status);
}
