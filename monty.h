#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list in form of a stack or queue
 * @n: integer
 * @prev: pointing to the previous element of the stack or queue
 * @next: pointing to the next element of the stack or queue
 * Description: doubly linked list node struct for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - func and opcode
 * @opcode: opcode
 * @f: func to handling the opcode
 * Description: opcode and its fun for stack, queues, LIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - struct of args from main
 * @av: file name from the command line
 * @ac: no. of args from the main
 * @line_number: no. of the file current line
 * Description: args to main from the cmd used in different funcs and are organized in a struct
 */
typedef struct args_s
{
	char *av;
	int ac;
	unsigned int line_number;
} args_t;

/**
 * struct data_s - external data to access inside funcs
 * @line: file line
 * @words: parsed line
 * @stack: stack ptr
 * @fptr: file ptr
 * @qflag: queue flag or stack
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

typedef stack_t dlistint_t;

extern data_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"

void monty(args_t *args);

void (*get_func(char **parsed))(stack_t **, unsigned int);
void push_handler(stack_t **stack, unsigned int line_number);
void pall_handler(stack_t **stack, unsigned int line_number);

void pint_handler(stack_t **stack, unsigned int line_number);
void pop_handler(stack_t **stack, unsigned int line_number);
void swap_handler(stack_t **stack, unsigned int line_number);
void add_handler(stack_t **stack, unsigned int line_number);
void nop_handler(stack_t **stack, unsigned int line_number);

void sub_handler(stack_t **stack, unsigned int line_number);
void div_handler(stack_t **stack, unsigned int line_number);
void mul_handler(stack_t **stack, unsigned int line_number);
void mod_handler(stack_t **stack, unsigned int line_number);

void rotl_handler(stack_t **stack, unsigned int line_number);
void rotr_handler(stack_t **stack, unsigned int line_number);
void stack_handler(stack_t **stack, unsigned int line_number);
void queue_handler(stack_t **stack, unsigned int line_number);

void pchar_handler(stack_t **stack, unsigned int line_number);
void pstr_handler(stack_t **stack, unsigned int line_number);

int count_word(char *s);
char **strtow(char *str);
void free_everything(char **args);

void free_all(int all);

#endif
