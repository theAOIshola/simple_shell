#include "shell.h"

/**
 * _atoi - convert alphabets to integers
 * @s: the string to convert to integer
 * Return: integer converted integer
 */

int _atoi(char *s)
{
	int integer = 0;
	int sign = 1;

	while (*s)
	{
		if (*s == '-')
		{
			sign *= -1;
		}

		if (*s >= '0' && *s <= '9')
		{
			integer = integer * 10 + (*s - '0');
		}
		else if ((*s < '0' || *s > '9') && *s != '-')
		{
			break;
		}
		s++;
	}
	if (sign < 1)
		integer = (-1 * integer);
	return (integer);
}

int main(void)
{
	int value;

	value = _atoi("123a");
	printf("%d", value);

	return (0);
}
