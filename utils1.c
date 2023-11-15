#include "monty.h"

/**
 * _itoa - turns an integer to characters
 * @n: to cinvert
 * Return: the corresponding integer
 */
char *_itoa(int n)
{
	int length;
	char *value;

	length = snprintf(NULL, 0, "%d", n);
	value = malloc(sizeof(char) * (length + 1));
	if (!value)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	sprintf(value, "%d", n);

	return (value);
}


/**
 * free_xtrn - frees the xtrn struct
 * Return: nothing
 */
void free_xtrn(void)
{
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
	stack_t *current_node = NULL;

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
		return (0);
	for (i = 0; nstr[i] != '\0' ; i++)
	{
		if (nstr[0] == '-')
			continue;
		if (nstr[i] < 48 || nstr[i] > 57)
			return (0);
	}

	return (1);
}
