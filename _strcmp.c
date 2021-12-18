#include "process.h"

/**
 * _strcmp - Comparar dos strings
 * @strings: Buffer 1.
 * @string: Buffer 2 to compare.
 * Return: Pointer con el objeto a comparar
 */

int _strcmp(char *strings, char *string)
{
	int i = 0;
	int compare = 0;

	if (strings == NULL || string == NULL)
		return (1);

	if (strlen(strings) != strlen(string))
		return (1);

	for (i = 0; strings[i]; i++)
	{
		if (strings[i] != string[i])
		{
			compare = strings[i] - string[i];
			break;
		}
		else
		{
			continue;
		}
	}
	return (compare);
}
