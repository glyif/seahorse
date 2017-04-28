#include "header.h"

/**
 * handle_c_line - analyizes a line of c
 * @line: line to analyze
 * @rf: readme file handle, it writes here
 *
 */
void handle_c_line(char *line, FILE *rf)
{
	static int inside_comment = 0;
	static char description[1024];
	
	if (!strcmp(line, "/**"))
	{
		inside_comment = 1;
		description[0] = 0;
	}
	else if (!strcmp(line, " */"))
	{
		inside_comment = 0;
	}
	else if (inside_comment)
	{
		if (strchr(line, '@') || strstr(line, "Return"))
		{
			add_new_argument(line);
		}
		else
		{
			if (inside_comment == 1 && strchr(line, '-'))
			{
				strcpy(description, strchr(line, '-') + 1);
				inside_comment = 2;
			}
		}
	}
	else if (line[0] > ' ' && line[0] != '{' && line[0] != '}' &&
           line[0] != '#' && !inside_comment)
	{
		if (strchr(line, '(') && strchr(line, ')') && !strchr(line, ';'))
			write_function_prototype(line, description, rf);
	}
}

/**
 * handle_c_file - handles c file. Opens file, extract info, and writes into
 * readme.md
 * @file_name: file name to handle
 * @dir_name: directory name, location of files to scan
 * @rf: readme file handle, it writes here
 *
 */
void handle_c_file(const char *file_name, const char *dir_name, FILE *rf)
{
	FILE *fc;
	char path[512], line[1024];
	size_t l;

	
	if (!is_c_file(file_name))
		return;
	
	strcpy(path, dir_name);
	if (dir_name[strlen(dir_name) - 1] != '/')
		strcat(path, "/");
	strcat(path, file_name);
	
	if ((fc = fopen(path, "r")) == NULL)
	{
		printf("Cannot open %s file\n", file_name);
		fprintf(rf, "\n\n");
		return ;
	}
	
	fprintf(rf, "### %s\n", file_name);
	
	while (!feof(fc))
	{
		fgets(line, sizeof(line), fc);
		l = strlen(line);
		
		if (line[l - 1] == '\n')
			line[l - 1] = 0;
		
		handle_c_line(line, rf);
	}
	
	fclose(fc);
	printf("Handling %s file\n", file_name);
	fprintf(rf, "\n\n");
}
