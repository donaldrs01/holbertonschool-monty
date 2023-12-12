#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

void pall(stack_t **stack)
{
	stack_t *temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
