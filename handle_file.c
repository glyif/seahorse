#include <stdio.h>

/**
 * handle_file - Opens file, extract info, and writes into readme.md
 * @file_name: file name to handle
 * @dir_name: directory name, location of files to scan
 * @rf: readme file handle, it writes here
 *
 */
void handle_file(const char *file_name, const char *dir_name, FILE *rf)
{
	fprintf(rf, "### %s\n", file_name);
	printf("Handling %s file\n", file_name);

	fprintf(rf, "\n\n");
}
