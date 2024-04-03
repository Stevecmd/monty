#include <stdio.h>
#include "monty.h"

/**
 * pstr - Prints the contents of a stack_t stack as a string.
 * @stack: Pointer to the head of the stack.
 * @line_cnt: Line counter for error messages (unused).
 *
 * Return: Nothing.
 */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current && current->n > 0 && current->n <= 127)
	{
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
