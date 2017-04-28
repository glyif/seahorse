#include "header.h"

extern argument_docs *first_arg;
extern argument_docs *last_arg;

void put_readme_header(FILE *rf, char *dir_name)
{
	FILE *a = NULL;
	char author[128] = {0};

	generate_author();
	a = fopen("username-temp.txt", "r");
	fgets(author, 128, a);
	fclose(a);
	remove("username-temp.txt");

	fprintf(rf, "<img src=\"https://www.holbertonschool.com/assets/holberton-logo-1cc451260ca3cd297def53f2250a9794810667c7ca7b5fa5879a569a457bf16f.png\" alt=\"Holberton logo\">\n\n");
	fprintf(rf, "# %s\n\n## Author: %s\n\n## Synopsis\n\n## Using\n\n## TODO\n\n## File Breakdown\n\n", dir_name, author);

}

void generate_author(void)
{
	char *args[4] = {"git", "config", "user.name", NULL};
	pid_t pid = fork();
	int fd2;

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
    fd2 = open("username-temp.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd2 < 0)
	{
		perror("catf1f2: f2");
		exit(2);
	}
    if (dup2(fd2, 1) != 1)
	{
		perror("catf1f2: dup2(f2, 1)");
		exit(1);
	}
	close(fd2);
	execvp(args[0], args);
	}
	else
	{
    waitpid(pid, NULL, 0);
	}
}

/**
 * write_function_prototyp - writes to README file the prototype of a function
 * @line: buffer to check
 * @description: description of function
 * @rf: file to write to
 */
void write_function_prototype(char *line, char *description, FILE *rf)
{
	argument_docs *current;

	fprintf(rf, "```c\n");
	fprintf(rf, "%s;\n", line);
	
	while (*description)
	{
		if (*description <= ' ')
			description++;
		else
			break;
	}
	
	if (strlen(description))
		fprintf(rf, "This function %s\n", description);
	
	fprintf(rf, "```\n\n");
	
	current = first_arg;
	
	while (current)
	{
		fprintf(rf, "- `%s` %s\n", current->name, current->descr);
		current = current->next;
	}

	delete_args(first_arg);
	first_arg = NULL;
	last_arg = NULL;
}
