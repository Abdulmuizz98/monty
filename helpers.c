#include "monty.h"
/*
 *
 */
void exec (char *line, unsigned int line_number, stack_t **rack)
{
	int j, status, arg;
	char *token, *token1;
	instruction_t commands[] = {
		{"push", push}, {"pall", pall}
	};
	
	token = strtok(line, " \n");
	token1 = strtok(NULL, "");

	j = 1;
	while (j > -1)
	{
		if (token == NULL)
			return;
		else
			if (strcmp(commands[j].opcode,token) == 0)
				break;
		j--;	
	}
	if (j == -1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		exit(EXIT_FAILURE);
	}
	/** Execute the command **/
	if (token1 == NULL)
		arg = -1;
	else
	{
		arg = atoi(token1);
		if (arg != 0)
			global_arg = arg;
		else if (check_atoi(token1) == 0)
			global_arg = 0;
		else 
			global_arg = -1;
	}	
	commands[j].f(rack, line_number);
}

/*

*/
int check_atoi(char* str)
{	
	char* ptr = str;
	while (*ptr == ' ')
		*ptr++; 
	return ((*ptr == '0') ? 0 : 1);
}
/**
 * rm_newline - gets getline content to be command ready
 * @nline: getline content
 * @nread: the length of getline content
 *
 * Return: pointer to the command ready line;
 */
char *rm_newline(char *nline, ssize_t nread)
{
	char *line;

	line = malloc(sizeof(char) * nread);
	strcpy(line, nline);
	line[nread - 1] = '\0';
	return (line);
}
