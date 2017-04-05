#include "header.h"

/**
 * handle_h_file - handles h files
 * @file_name: file name to handle
 * @dir_name: directory name, location of files to scan
 * @rf: readme file handle, it writes here
 *
 */
void handle_h_file(const char *file_name, const char *dir_name, FILE *rf)
{
	FILE *fc;

	if (is_h_file(file_name))
	{
		char path[512];

		fprintf(rf, "### %s\n", file_name);

		fprintf(rf, "This is a header file containing all of the prototypes \
				necessary for testing with a main function.");

		fprintf(rf, "\n\n");

		strcpy(path, dir_name);

		if (dir_name[strlen(dir_name) - 1] != '/')
			strcat(path, "/");

		strcat(path, file_name);

		fc = fopen(path, "r");

		if (fc)
			fclose(fc);
	}
}
