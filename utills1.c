#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _itoa - turns an integer to characters
 * @n: integer to convert
 * Return: the corresponding string
 */
char *_itoa(int n)
{
	int length;
	char *value;

	length = snprintf(NULL, 0, "%d", n);
	value = malloc(sizeof(char) * (length + 1));
	if (value == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (snprintf(value, length + 1, "%d", n) < 0)
	{
		fprintf(stderr, "Error: snprintf failed\n");
		exit(EXIT_FAILURE);
	}

	return value;
}

/**
 * free_xtrn - frees the xtrn struct
 * Return: nothing
 */
void free_xtrn(void)
{
	if (mt.m_script != NULL)
		fclose(mt.m_script);

	free(mt.buffer);
	free_stack(mt.stack);
}

/**
 * free_stack - frees the xtrn stack
 * @head: the stack to free
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *current_node;

	while (head != NULL)
	{
		current_node = head;
		head = head->next;
		free(current_node);
	}
}

/**
 * my_isdigit - check if a string contains digits only
 * @nstr: string to be checked
 * Return: 1 if digit, 0 if not digit
 */
int my_isdigit(char *nstr)
{
	int i;

	if (nstr == NULL)
		return 0;

	for (i = 0; nstr[i] != '\0'; i++)
	{
		if (nstr[0] == '-')
			continue;

		if (nstr[i] < '0' || nstr[i] > '9')
			return 0;
	}

	return 1;
}
