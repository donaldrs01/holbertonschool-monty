#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

void push(stack_t **stack, unsigned int line_number, char *argument)
{
	int arg = atoi(argument);

	if (arg == 0 && strcmp(argument, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = arg;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
