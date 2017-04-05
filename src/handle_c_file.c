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
	if (is_c_file(file_name))
	{
		char path[512];
		FILE *fc;

		strcpy(path, dir_name);

		if (dir_name[strlen(dir_name) - 1] != '/')
			strcat(path, "/");

		strcat(path, file_name);

		fc = fopen(path, "r");

		fprintf(rf, "### %s\n", file_name);
		if (fc)
		{
			int inside_comment = 0;

			/* 1024 chars is enough to store one line from file */
			while (!feof(fc))
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

						fprintf(rf, "```c\n");
						fprintf(rf, "%s;\n", line);
						fprintf(rf, "```\n");
					}
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
