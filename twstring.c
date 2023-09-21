#include "monty.h"
#include "lists.h"

/**
 * count_word - helper func
 * @s: string to check
 * Return: no. of words
 */
int count_word(char *s)
{
	int flag = 0, a;
	int m = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			m++;
		}
	}

	return (m);
}
/**
 * **strtow - func spliting a string into words
 * @str: string to split
 * Return: pointer to an array of strings - Success, NULL - fail
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, j = 0, len = 0, wrd, c = 0, start, end;

	len = strlen(str);
	wrd = count_wrd(str);
	if (wrd == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (wrd + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[j] = tmp - c;
				j++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[j] = NULL;

	return (matrix);
}

/**
 * free_everything - func freeing strings arrayss
 * @args: strings arrays being freed
 */
void free_everything(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}
