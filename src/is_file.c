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

/**
 * handle_c_h_files - checks if it is a h file or c file
 * dir_name: directory name
 * rf: file to check
 * 
 * Return: 1 if h or c, 0 if not
 */

int handle_c_h_files(char *dir_name, FILE *rf)
{
	DIR *d;
	struct dirent *dir;
	int i = 0;
	
	while (i < 2)
	{
		if ((d = opendir(dir_name)) == NULL)
		{
			printf("\nInvalid directory\nCannot scan there\n");
			return (-1);
		}
		while ((dir = readdir(d)) != NULL)
		{
			if (strcmp(dir->d_name, ".") && strcmp(dir->d_name, ".."))
			{
				if (dir->d_type & DT_REG)
				{
					if (i == 0)
						handle_h_file(dir->d_name, dir_name, rf);
					else
						handle_c_file(dir->d_name, dir_name, rf);
				}
			}
		}
		closedir(d);
		i += 1;
	}
	return (0);
}
