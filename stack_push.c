#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = global.argument;
	long int num;

	errno = 0;
	num = validate_input(n, line_cnt);

	if (global.data_struct == 1)
	{
		if (!add_node(stack, (int)num))
			handle_add_error(line_cnt);
	}
	else
	{
		if (!queue_node(stack, (int)num))
			handle_queue_error(line_cnt);
	}
}

/**
 * validate_input - validate input string and convert it to integer
 * @n: input string
 * @line_cnt: line number
 *
 * Return: converted integer
 */
long int validate_input(char *n, unsigned int line_cnt)
{
	char *endptr;
	long int num;

	if (!n || *n == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	errno = 0;
	num = strtol(n, &endptr, 10);

	if (errno != 0 || *endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	return (num);
}

/**
 * handle_add_error - handle error when adding node to stack
 * @line_cnt: line number
 *
 * Return: void
 */
void handle_add_error(unsigned int line_cnt)
{
	fprintf(stderr, "L%d: failed to add node to stack\n", line_cnt);
	exit(EXIT_FAILURE);
}

/**
 * handle_queue_error - handle error when adding node to queue
 * @line_cnt: line number
 *
 * Return: void
 */
void handle_queue_error(unsigned int line_cnt)
{
	fprintf(stderr, "L%d: failed to add node to queue\n", line_cnt);
	exit(EXIT_FAILURE);
}
