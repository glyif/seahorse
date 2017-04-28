#include "header.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: list of arguments
 *
 * Return: 0
 */

argument_docs *first_arg = NULL;
argument_docs *last_arg = NULL;

int main(int argc, char **argv)
{
  FILE *rf = NULL;

  if (argc <= 2)
  {
	  printf("\nUsing\nseahorse <Directory> <Name of README file>\n");
	  return (-1);
  }

  if ((rf = fopen(argv[2], "w")) == NULL)
  {
	  printf("\nCannot create readme file\n");
	  return (-1);
  }
  put_readme_header(rf, argv[1]);

  if (handle_c_h_files(argv[1], rf) == -1)
	  return (-1);

  fclose(rf);
  return 0;
}
