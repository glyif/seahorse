/**
 * word_count - parces string for space
 * @s: string
 *
 * Return: number of words
 */

int word_count(char *s)
{
	int i, j;

	for (i = 0, j = 0; s[i] != '\0'; i++)
		if (s[i] == ' ')
			j++;

	if (s[i - 1] == ' ')
		return (j);
	else
		return (j + 1);
}

/**
 * copy_array - copies array
 * @from: from
 * @to: to
 * @start: index of start of copy
 * @index: index of array of pointers
 *
 * Return: nothing;
 */

void copy_array(char *from, char **to, int start, int index)
{
	int i;

	if (start != 0)
		start = start + 1;

	for (i = 0; from[i] != ' ' && from[i] != '\0'; i++, start++)
	{
		to[index][i] = from[start];
	}

	to[index][i] = '\0';

}

/**
 * my_argv - my argv implementation
 * @s: string
 *
 * Return: array of pointers
 */

char **my_argv(char *s)
{

	int i, point, w, words;

	char **ar;

	words = word_count(s);

	ar = malloc(sizeof(*ar) * words);

	for (i = 0, point = 0, w = 0; w < words; i++)
	{
		if (s[i] == ' ' || s[i] == '\0')
		{
			if (w == 0)
				ar[w] = malloc(sizeof(char) * (i - point + 1));
			else
				ar[w] = malloc(sizeof(char) * (i - point));
			
			if (ar[w] == NULL)
				return (NULL);

			copy_array(s, ar, point, w);
			point = i;
			w++;
		}
	}

	return (ar);
}
