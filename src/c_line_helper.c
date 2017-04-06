#include "header.h"

argument_docs *first_arg = NULL;
argument_docs *last_arg = NULL;

/**
 * write_function_prototype - writes the function prototype documentation
 * @line: line of C
 * @rf: readme file, writes to here
 */
void write_function_prototype(char *line, FILE *rf)
{
	argument_docs *current;

	current = first_arg;

	/* print function prototype into the readme file */
	fprintf(rf, "```c\n");
	fprintf(rf, "%s;\n", line);
	fprintf(rf, "```\n\n");

	while(current)
	{
		fprintf(rf, "- `%s` %s\n", current->name, current->descr);
		current = current->next;
	}
			
	delete_args(first_arg);
	first_arg = NULL;
	last_arg = NULL;
}

/**
 * add_new_argument - adds new node to arguments linked list
 * @line: line of C
 */
void add_new_argument(char *line)
{
	argument_docs *current = NULL;
	char *begin_arg_name;
	char *end_arg_name;

	current = malloc(sizeof(argument_docs));
	memset(current, 0, sizeof(sizeof(argument_docs)));
	current->next = NULL;

	begin_arg_name = strchr(line, '@');
	if (!begin_arg_name)
		begin_arg_name = strstr(line, "Return");
	end_arg_name = strchr(begin_arg_name, ' ');

	strncpy(current->name, begin_arg_name, end_arg_name - begin_arg_name - 1);
	strcpy(current->descr, end_arg_name);

	if (!last_arg)
	{
		first_arg = current;
	}
	else
	{
		last_arg->next = current;					
	}					
	last_arg = current;
}
