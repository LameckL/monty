#include "monty.h"
#include "lists.h"

data_t data = DATA_INIT;

/**
 * monty - this is a helper func to the main
 * @args: struct ptr of the args from main
 * Description: opens,reads the file with the opcodes
 * and call the func finding the corresponding executing func
 */
void monty(args_t *args)
{
	size_t len = 0;
	int recei = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (args->ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	data.fptr = fopen(args->av, "r");
	if (!data.fptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args->av);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args->line_number++;
		recei = getline(&(data.line), &len, data.fptr);
		if (recei < 0)
			break;
		data.words = strtow(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_all(0);
			continue;
		}
		code_func = get_func(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, args->line_number, data.words[0]);
			free_all(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), args->line_number);
		free_all(0);
	}
	free_all(1);
}

/**
 * main - entry point
 * @argc: no. of args
 * @argv: array of the ars
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	args_t args;

	args.av = argv[1];
	args.ac = argc;
	args.line_number = 0;

	monty(&args);

	return (EXIT_SUCCESS);
}
