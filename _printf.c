#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function tha prints
 * @format: the format
 * Return: Printed characters
 */

int _printf(const *format, ...)
{
	int i, printed, printed_chars;
	int flags, width, precision, size, buff_ind;

	va_list;

	char buffer[BUFF_SIZE];

	printed = 0;
	printed_chars = 0;
	buff_ind = 0;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			i++;
			printed = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed
		}
	}
	printed_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
/**
 * printed_buffer - function that prints contents of the buffer if it is there
 * @buffer: Array of chars
 * @buff_ind: length of char
 * Return: void
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
