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

		/* Open directrory to scan for files*/
		d = opendir(argv[1]);

		/* check directory is valid */
		if (d)
		{
			FILE *rf = fopen(argv[2], "w");

			if (rf)
			{
				fprintf(rf, "## File Breakdown\n");

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
							handle_file(dir->d_name, argv[1], rf);
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
		printf("\nUsing\nseahorse <Direcory> <name of Readme file>\n");
	}

	return (0);
}
