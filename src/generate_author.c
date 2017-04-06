#include "header.h"

/**
 * generate_author - generates a file containing your github username
 */

void generate_author(void)
{
	char *args[4];
	int fd2;
	int to_out;

	pid_t pid = fork();

	if (pid == -1)
		perror("fork");

	if (pid == 0)
	{
		fd2 = open("username.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd2 < 0)
		{
			perror("f2: f2");
			exit(2);
		}

		to_out = dup2(fd2, STDOUT_FILENO);

		if (to_out != STDOUT_FILENO)
		{
			perror("f2: dup2(f2, 1)");
			exit(1);
		}

		close(fd2);

		args[0] = "git";
		args[1] = "config";
		args[2] = "user.name";
		args[3] = NULL;
		execvp(args[0], args);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
