#include "header.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: list of arguments
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		DIR *d;
		struct dirent *dir;
		FILE *rf;

		/* Open directory to scan for files*/
		d = opendir(argv[1]);

		/* check directory is valid */
		if (d)
		{
			rf = fopen(argv[2], "w");
			if (rf)
			{
				fprintf(rf, "# %s\n\n", "title");

				fprintf(rf, "## Author: %s\n\n", "author");

				fprintf(rf, "## Synopsis\n\n");

				fprintf(rf, "## File Breakdown\n");

				while ((dir = readdir(d)) != NULL)
				{
					/* Skip . and ..*/
					if (strcmp(dir->d_name, ".") && strcmp(dir->d_name, ".."))
					{
						/* skip not regular files (directories, etc) */
						if (dir->d_type & DT_REG)
						{
							/* handle file*/
							handle_h_file(dir->d_name, argv[1], rf);
						}
					}
				}
				closedir(d);


				d = opendir(argv[1]);
				/* Extract file name */
				while ((dir = readdir(d)) != NULL)
				{
					/* Skip . and ..*/
					if (strcmp(dir->d_name, ".") && strcmp(dir->d_name, ".."))
					{
						/* skip not regular files (directories, etc) */
						if (dir->d_type & DT_REG)
						{
							/* handle file*/
							handle_c_file(dir->d_name, argv[1], rf);
						}
					}
				}
				/* close output file */
				fclose(rf);
			}
			else
			{
				printf("\nCannot create readme file\n");
			}
			closedir(d);
		}
		else
		{
			printf("\nInvalid directory\nCannot scan there\n");
		}
		return (0);
	}
	else
	{
		printf("\nUsing\nseahorse <Directory> <name of Readme file>\n");
	}
	return (0);
}
