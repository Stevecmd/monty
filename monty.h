#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>

#define INSTRUCTIONS              \
	{                           \
		{"push", push},       \
		    {"pall", pall},   \
		    {"pint", pint},   \
		    {"pop", pop},     \
		    {"swap", swap},   \
		    {"nop", nop},     \
		    {"div", _div},    \
		    {"mul", _mul},    \
		    {"add", _add},    \
		    {"sub", _sub},    \
		    {"mod", mod},     \
		    {"pchar", pchar}, \
		    {"pstr", pstr},   \
		    {"rotl", rotl},   \
		    {"rotr", rotr},   \
		{                     \
			NULL, NULL      \
		}                     \
	}

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
* struct help - argument for the current opcode
* @data_struct: stack mode, stack (default) and queue
* @argument: the arguments of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct help
{
	int data_struct;
	char *argument;
} help;
extern help global;


/* monty_main.c */
int main(int argc, char **argv);
void file_error(char *argv);
void error_usage(void);


/* opcode.c */
void opcode(stack_t **stack, char *str, unsigned int line_cnt);


/* stack_add.c */
void _add(stack_t **stack, unsigned int line_cnt);


/*stack_division.c */
void _div(stack_t **stack, unsigned int line_cnt);


/* stack_modulus.c */
void mod(stack_t **stack, unsigned int line_cnt);


/* stack_multiplications.c */
void _mul(stack_t **stack, unsigned int line_cnt);


/* stack_nop.c */
void nop(stack_t **stack, unsigned int line_cnt);


/* stack_operations.c */
stack_t *queue_node(stack_t **stack, const int n);
stack_t *add_node(stack_t **stack, const int n);
size_t print_stack(const stack_t *stack);
void free_stack(stack_t *stack);


/* stack_pchar.c */
void pchar(stack_t **stack, unsigned int line_cnt);


/* stack_pint.c */
void pint(stack_t **stack, unsigned int line_cnt);


/* stack_pop.c */
void pop(stack_t **stack, unsigned int line_cnt);


/* stack_print_string.c */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)));


/* stack_print.c */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)));


/* stack_push.c */
void push(stack_t **stack, unsigned int line_cnt);
long int validate_input(char *n, unsigned int line_cnt);
void handle_add_error(unsigned int line_cnt);
void handle_queue_error(unsigned int line_cnt);

/* stack_rotate_left.c */
void rotl(stack_t **stack, unsigned int line_cnt);


/* stack_rotate_right.c */
void rotr(stack_t **stack, unsigned int line_cnt);


/* stack_subtract.c */
void _sub(stack_t **stack, unsigned int line_cnt);


/* string_checks.c */
int is_digit(char *string);
int isnumber(char *str);


/* swap.c */
void swap(stack_t **stack, unsigned int line_cnt);


#endif /* MONTY_H */
