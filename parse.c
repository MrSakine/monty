#include "monty.h"

/**
 * remove_any_digit - remove digit from string
 * @str: string input
 *
 * Return: void
 */
void remove_any_digit(char *str)
{
	int i, j;

	j = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[j] = str[i];
			j++;
		}
	}

	str[j] = '\0';
}

/**
 * get_fp_content - get file content line by line
 * @fp: file object
 *
 * Return: void
 */
void get_fp_content(FILE *fp)
{
	size_t len = 0, i = 0, j;
	ssize_t read;

	while ((read = getline(&(monty_instance.line), &len, fp)) != -1)
	{
		j = 0;
		for (i = 0; monty_instance.line[i]; i++)
		{
			if (monty_instance.line[i] != ' ')
			{
				monty_instance.line[j] = monty_instance.line[i];
				j++;
			}
		}

		monty_instance.line[j - 1] = monty_instance.line[j - 1] == '\n' ? '\0' : monty_instance.line[j - 1];
		execute_by_line(monty_instance.line);
	}

	free(monty_instance.line);
}

/**
 * parse_input - parse line from file
 * @value: line from file
 *
 * Return: NULL
 */
char **parse_input(char *value)
{
	monty_instance.fp = fopen(value, "r");
	if (monty_instance.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", value);
		exit(EXIT_FAILURE);
	}

	get_fp_content(monty_instance.fp);
	fclose(monty_instance.fp);

	return (NULL);
}
