#include "header.h"

extern argument_docs *first_arg;
extern argument_docs *last_arg;

/**
 * delete_args - delete linked list recursively
 * @args: pointer to the beginning of the linked list
 */
void delete_args(argument_docs *args)
{
	if (args)
	{
		delete_args(args->next);
		free(args);
	}
}

/**
 * add_new_argument - adds an argument line to linked lists
 * @line: line to add
 */
void add_new_argument(char *line)
{
	char *begin_arg_name;
	char *end_arg_name;
	argument_docs *current = NULL;
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
		first_arg = current;
	else
		last_arg->next = current;

	last_arg = current;
}
