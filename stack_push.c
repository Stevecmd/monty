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
	char *endptr;
	long int num;

	errno = 0; /* Reset errno before the call */

	num = strtol(n, &endptr, 10);

	/* Check for conversion errors */
	if ((errno == ERANGE && (num == LONG_MAX || num == LONG_MIN)) || (errno != 0 && num == 0))
	{
		fprintf(stderr, "L%d: conversion error: %s\n", line_cnt, strerror(errno));
		exit(EXIT_FAILURE);
	}

	/* Check if the entire string was converted */
	if (endptr == n || *endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	/* Check for integer overflow or underflow */
	if (num > INT_MAX || num < INT_MIN)
	{
		fprintf(stderr, "L%d: push value exceeds integer limits\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	/* Add the integer to the stack or queue */
	if (global.data_struct == 1)
	{
		if (!add_node(stack, (int)num))
		{
			fprintf(stderr, "L%d: failed to add node to stack\n", line_cnt);
			exit(EXIT_FAILURE);
		}
	} else
	{
		if (!queue_node(stack, (int)num))
		{
			fprintf(stderr, "L%d: failed to add node to queue\n", line_cnt);
			exit(EXIT_FAILURE);
		}
	}
}
