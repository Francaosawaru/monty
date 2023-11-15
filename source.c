#include "monty.h"

xtrn_t mt;

/**
 * get_op - gets the operation
 * @opcode: opcode namd
 * @line: linevto check
 * Return: none
 */
void (*get_op(char *opcode, unsigned int line))(stack_t **, unsigned int)
{
	instruction_t op_code[] = {
		{"mod", _mod}, {"add", _add}, {"mul", _mul}, {"sub", _sub},
		{"div", _div}, {"pop", _pop}, {"nop", _nop},
		{"push", _push}, {"pint", _pint}, {"pchar", _pchar},
		{"pall", _pall}, {"swap", _swap}, {"pstr", _pstr},
		{"rotr", _rotr}, {"rotl", _rotl}, {"stack", _stack},
		{"queue", _queue}, {NULL, NULL},
	};
	int i, boolean;

	for (i = 0; op_code[i].opcode; i++)
	{
		boolean = strcmp(opcode, op_code[i].opcode);
		if (boolean == 0)
			return (op_code[i].f);
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}

/**
 * setup_monty - opens and runs monty file
 * @argv: argument vector
 * @line_no: not telling you
 * Return: nil
 */
void setup_monty(char **argv, unsigned int line_no)
{
	char *line, *cmd;
	void (*func)(stack_t **stack, unsigned int line_no);

	mt.m_script = fopen(argv[1], "r");
	if (mt.m_script == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		line_no++;

		mt.buffer = malloc(sizeof(char) * 1024);
		if (mt.buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		line = fgets(mt.buffer, 1024, mt.m_script);
		if (line == NULL)
			break;

		cmd = strtok(mt.buffer, " \n\t\a\r");
		mt.value = strtok(NULL, " \n\t\a\r");
		if (cmd != NULL && cmd[0] != 35)
		{
			func = get_op(cmd, line_no);
			func(&mt.stack, line_no);
		}
		free(mt.buffer);
	}
	free_xtrn();
}

/**
 * main - runs the monty script in a noninteractive mode
 * @argv: the arg vector
 * @argc: argument count
 *
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mt.stack = NULL;
	mt.buffer = NULL;
	mt.value = NULL;
	mt.type = 1;

	setup_monty(argv, 0);

	return (0);
}
