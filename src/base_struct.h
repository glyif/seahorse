#ifndef ARGUMENT
#define ARGUMENT
/**
 * struct argument_docs - struct for separating out argument for documenation
 * @name: name of argument
 * @descr: description of argument
 * @next: pointer to next node that contains next argument or NULL
 */

typedef struct argument_docs
{
	char name[512];
	char descr[1024];
	struct argument_docs *next;
} argument_docs;
#endif
