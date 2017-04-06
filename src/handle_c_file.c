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
		size_t l;

		strcpy(path, dir_name);
		if (dir_name[strlen(dir_name) - 1] != '/')
			strcat(path, "/");
		strcat(path, file_name);

		fc = fopen(path, "r");

		fprintf(rf, "### %s\n", file_name);
		if (fc)
		{
			while (!feof(fc))
			{
				char line[1024] = {0};

				/* read file line by line */
				fgets(line, sizeof(line), fc);

				l = strlen(line);
				/* strip last \n in the line */
				if (line[l - 1] == '\n')
					line[l - 1] = 0;

				handle_c_line(line, rf);
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
