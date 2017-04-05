#include "header.h"

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
