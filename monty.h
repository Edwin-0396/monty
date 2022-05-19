#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
**/

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
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
**/

typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct handler - helper functions
* @token2: pointer to token 1
* @buffer: pointer to string returned from getline
* @fp: pointer to file
* @head: pointer to beginning of list
* @line_number: line number of file
* @n: number of bytes read
* @token1: pointer to token 2
* @queueflag: flag for queue function
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
**/

typedef struct handler
{
	char *token2;
	char *buffer;
	FILE *fp;
	stack_t *head;
	size_t line_number;
	size_t n;
	char *token1;
	int queueflag;
} handlers;
extern handlers handle;

handlers handle;

/** OP CODE FUNCTIONS **/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);

/** PROTOTYPES **/
void malloc_error(void);
int monty_interpreter(void);
int opcode_instruction(void);
int _isnumber(void);
int count_words(char *str);
void free_all(void);
void free_dlistint(stack_t *head);

/** ERROR THROWERS **/
void error_argv(void);
void invalid_instrution(int line, char *opcode);

#endif
