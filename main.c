#include "monty.h"
int main(int argc, char *argv[])
{
	char *content, *c_line;
	FILE *file;
	size_t size = 0, count = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		count++;
		content = NULL;
		read_line = getline(&content, &size, file);
		if (read_line > 0)
		{
		//	c_line = clean_line(content);
			execute(c_line, &stack);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
