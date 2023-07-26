#include "shell.h"

char **commands = NULL;
char *line = NULL;
char *shell_name = NULL;
int status = 0;

/**
 * main - the main shell code
 * @argc: number of arguments passed
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int args __attribute__((unused)), char **argv)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	shell_name = argv[0];
	while (1)
	{
		non_interactive();
		print(" ($) ", STDOUT_FILENO);
		if (gtline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
		remove_newline(line);
		remove_comment(line);
		commands = tokenizer(line, ";");

		for (i = 0; command[i] != NULL; I++)
		{
			current_command = tokenizer(commands[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = parse_command(current_command[0]);
			initializer(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);
	return (status);
}