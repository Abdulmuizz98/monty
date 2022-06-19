#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int global_arg;
/**
 * main - the monty interpreter program
 * @argc: ac
 * @argv: av
 *
 * Return: 0 when it finishes.
 */
int main(int argc, char **argv)
{
	FILE *stream;
	stack_t *head;
	unsigned int line_number = 0;
	size_t len = 0;
	ssize_t nread;
	char *line = NULL;

	head = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		line_number++;
		exec(line, line_number, &head);
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
