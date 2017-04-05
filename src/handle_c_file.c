#include "header.h"

/**
 * handle_c_file - handles c files
 * @file_name: file name to handle
 * @dir_name: directory name, location of files to scan
 * @rf: readme file handle, it writes here
 *
 */
void handle_c_file(const char *file_name, const char *dir_name, FILE *rf)
{
	char path[512];
	char *begin_arg_name;
	char *end_arg_name;
	FILE *fc;

	argument_docs *first_arg;
	argument_docs *last_arg;
	argument_docs *current;

	if (is_c_file(file_name)) 
	{
		strcpy(path, dir_name);
                if (dir_name[strlen(dir_name)-1] != '/')
			strcat(path, "/");
		strcat(path, file_name);
		
		fc = fopen(path, "r");

		fprintf(rf, "### %s\n", file_name);
		if (fc) 
		{
			int inside_comment = 0;

			/* 1024 chars is enough to store one line from file */
			while(!feof(fc))
			{
				char line[1024] = {0};

				/* read file line by line */
				fgets(line, sizeof(line), fc);
				if (!strcmp(line, "/**\n"))
				{
					/* Comments opened */
					inside_comment = 1;
				}
				else if (!strcmp(line, " */\n"))
				{
					/* Comments closed */
					inside_comment = 0;
				}
				else if (inside_comment)
				{
					/* find argument description */					
					if (strchr(line, '@'))
					{
						size_t l = strlen(line);
						/* strip last \n in the line */
						if (line[l-1]=='\n')
							line[l-1] = 0;

						current = malloc(sizeof(argument_docs));
						memset(current, 0, sizeof(sizeof(argument_docs)));
						current->next = NULL;

						begin_arg_name = strchr(line, '@');
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
				}
				else if (line[0] > ' ' && line[0] != '{' && line[0] != '}' && line[0] != '#' && !inside_comment)
				{
					/* check line has () and does not have ;*/
					if (strchr(line, '(') && strchr(line, ')') && !strchr(line, ';'))
					{
						size_t l = strlen(line);
						/* strip last \n in the line */
						if (line[l - 1] == '\n')
							line[l - 1] = 0;

						/* print function prototype en the file */
						fprintf(rf, "```c\n");
						fprintf(rf, "%s;\n", line);
						fprintf(rf, "```\n\n");

						current = first_arg;
						while (current)
						{
							fprintf(rf, "- `%s` %s\n", current->name, current->descr);
							current = current->next;
						}
					}

					delete_args(first_arg);
					first_arg = NULL;
					last_arg = NULL;
				}
			}

			fclose(fc);
			printf("Handling %s file\n", file_name);
		}
		else
		{
			printf("Cannot open %s file\n", file_name);
		}
		fprintf(rf, "\n\n");
	}
}
