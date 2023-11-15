#include "monty.h"

/**
 * _mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void _mod(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	char *num;
	int prev_is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_xtrn();
		fprintf(stderr, "L%d: can't mod, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	for (; temp->next->next; temp = temp->next)
		;
	if (temp->next->n == 0)
	{
		free_xtrn();
		fprintf(stderr, "L%d: division by zero\n", lnum);
		exit(EXIT_FAILURE);
	}

	num = _itoa(temp->n % temp->next->n);

	_pop(stack, lnum);
	_pop(stack, lnum);

	mt.value = num;
	prev_is_stack = mt.type;
	mt.type = 1;
	_push(stack, lnum);
	mt.type = prev_is_stack;

	free(num);
}

/**
 * _pchar - prints the char at the top of the stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	int num;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lnum);
		free_xtrn();
		exit(EXIT_FAILURE);
	}

	for (; temp->next; temp = temp->next)
		;
	num = temp->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lnum);
		free_xtrn();
		exit(EXIT_FAILURE);
	}

	putchar(num);
	putchar('\n');
}

/**
 * _pstr - prints the string starting from the top
 * @stack: stack
 * @lnum: line number
 *
 * Return:void
 */
void _pstr(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	int num;

	if (!(*stack))
		putchar('\n');
	else
	{
		for (; temp->next; temp = temp->next)
			;

		for (; temp; temp = temp->prev)
		{
			num = temp->n;
			if (num == 0 || num < 0 || num > 127)
				break;

			putchar(num);
		}
		putchar('\n');
	}

	(void)lnum;
}

/**
 * _rotl - rotates the stack to the top
 * becomes the top element
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack, *prev;

	if (*stack && (*stack)->next)
	{
		for (; temp->next; temp = temp->next)
			;

		if (temp->prev == *stack)
		{
			prev = *stack;
			prev->prev = temp;
			prev->next = NULL;
			temp->prev = NULL;
			temp->next = prev;
			*stack = temp;
		}
		else
		{
			prev = temp->prev;
			prev->next = NULL;

			temp->next = *stack;
			temp->prev = NULL;
			(*stack)->prev = temp;
			*stack = temp;
		}
	}

	(void)lnum;
}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack, *prev;

	if (*stack && (*stack)->next)
	{
		prev = temp;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;

		for (temp = *stack; temp->next; temp = temp->next)
			;

		prev->prev = temp;
		prev->next = NULL;
		temp->next = prev;
	}

	(void)lnum;
}
