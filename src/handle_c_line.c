#include "header.h"

/**
 * handle_c_line - handles a line of C code
 * @line: line of C code
 * @rf: readme file handle, write to here
 */
void handle_c_line(char *line, FILE *rf)
{
	static int inside_comment;

	if (!strcmp(line, "/**"))
	{
		/* Comments opened */
		inside_comment = 1;
	}
	else if (!strcmp(line, " */"))
	{
		/* Comments closed */
		inside_comment = 0;
	}
	else if (inside_comment)
	{
		/* find argument description */
		if (strchr(line, '@') || strstr(line, "Return"))
		{
			add_new_argument(line);
		}
	}
	else if (line[0] > ' ' && line[0] != '{' && line[0] != '}' &&
			line[0] != '#' && !inside_comment)
	{
		/* check line has () and does not have ;*/
		if (strchr(line, '(') && strchr(line, ')') && !strchr(line, ';'))
		{
			write_function_prototype(line, rf);
		} 
	}
}
