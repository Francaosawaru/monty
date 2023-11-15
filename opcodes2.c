#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: stack
 * @line_no: line number
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = *stack;
	char *num;
	int prev_is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_xtrn();
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	for (; temp->next->next; temp = temp->next)
		;
	num = _itoa(temp->n + temp->next->n);

	_pop(stack, line_no);
	_pop(stack, line_no);

	mt.value = num;
	prev_is_stack = mt.type;
	mt.type = 1;
	_push(stack, line_no);
	mt.type = prev_is_stack;

	free(num);
}

/**
 * _nop - does nothing to the stack
 * @stack: stack
 * @line_no: line number
 *
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
}

/**
 * _sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: stack
 * @line_no: line number
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = *stack;
	char *num;
	int prev_is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_xtrn();
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	for (; temp->next->next; temp = temp->next)
		;
	num = _itoa(temp->n - temp->next->n);

	_pop(stack, line_no);
	_pop(stack, line_no);

	mt.value = num;
	prev_is_stack = mt.type;
	mt.type = 1;
	_push(stack, line_no);
	mt.type = prev_is_stack;

	free(num);
}

/**
 * _mul - multiplies the top element of the stack by
 * the second top element of the stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	char *num;
	int prev_is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_xtrn();
		fprintf(stderr, "L%d: can't mul, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	for (; temp->next->next; temp = temp->next)
		;
	num = _itoa(temp->n * temp->next->n);

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
 * _div - divides the second top element of the stack from
 * the top element of the stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	char *num;
	int prev_is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_xtrn();
		fprintf(stderr, "L%d: can't div, stack too short\n", lnum);
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

	num = _itoa(temp->n / temp->next->n);

	_pop(stack, lnum);
	_pop(stack, lnum);

	mt.value = num;
	prev_is_stack = mt.type;
	mt.type = 1;
	_push(stack, lnum);
	mt.type = prev_is_stack;

	free(num);
}
