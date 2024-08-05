#include "main.h"

/**
 * get_flags - function that calculates active flags
 * @format: formated string to print arguments
 * @i: takes the parameter
 * Return: Flags
 */

int get_flags(const char *format, int *i)
{
	int j, curr_i, flags;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const inet FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	flags = 0;

	for (curr_i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break
			}
		if (FLAGS_CH[j] == 0)
			break
	}
	*i = curr_i - 1;
	return (flags);
}
