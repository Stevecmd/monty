#include <stdio.h>
#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: Pointer to the head of the stack.
 * @line_cnt: Line number where the swap operation is executed.
 *
 * Return: void
 *
 * Assumptions:
 *   - The stack is implemented as a doubly linked list.
 *   - Each node in the stack has an integer value.
 */
void swap(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
