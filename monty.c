#include "monty.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int global_arg;
/**
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
		/*nline = rm_newline(line, nread);		
		printf("$%s$", nline);
		fflush(stdout);*/
		exec(line, line_number, &head);
		/*free(nline);*/
	}
	return (0);

}

/*
main - monty.c
	- Open the file and preepare for reading
	- Loop Read from the file per line.
	- Each line should be an instruction.( you may use the instruction obj)
commands (
	- push.c (for the push command)
*/	
