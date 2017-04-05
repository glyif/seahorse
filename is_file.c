#include "header.h"

/**
 * is_c_file - checks if a file is a c file
 * @file_name: name of the file
 *
 * Return: 1 if yes, 0 if no
 */

int is_c_file(const char *file_name)
{
	size_t file_name_len = strlen(file_name);

	if (file_name_len > 2)
	{
		if (!strcmp(&file_name[file_name_len - 2], ".c"))
			return (1);
	}
	return (0);
}

/**
 * is_h_file - checks if a file is a h file
 * @file_name: name of the file
 *
 * Return: 1 if yes, 0 if no
 */

int is_h_file(const char *file_name)
{
	size_t file_name_len = strlen(file_name);

	if (file_name_len > 2)
	{
		if (!strcmp(&file_name[file_name_len - 2], ".h"))
			return (1);
	}
	return (0);
}
