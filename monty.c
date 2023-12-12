#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t buff = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((buff = getline(&line, &len, file)) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \n");
		char *argument = strtok(NULL, " \n");
		if (strcmp(opcode, "push") == 0)
		{
			push(&stack, line_number, argument);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		line = NULL;
		len = 0;
	}

	free(line);

	while (stack != NULL)
	{
		stack_t *tmp = stack;
		stack = stack->next;
		free(tmp); /* free the stack by creating temp nodes */
	}

	fclose(file);

	return(0);
}
