#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack has less than two elements\n",
				line_cnt);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero is not allowed\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_cnt); /* For top node */
	(*stack)->n = result;
}
