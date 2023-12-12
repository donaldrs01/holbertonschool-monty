#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of stack
 * @n: integer
 * @prev: points to previous element of stack
 * @next: points to next element of stack
 *
 * Description: doubly linked list node struct
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

/* function declarations */

void push(stack_t **stack, unsigned int line_number, char *argument);
void pall(stack_t **stack);
int main(int argc, char *argv[]);

#endif
