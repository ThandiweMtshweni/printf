#include "main.h"

/**
 * handle_write_char - Function that prints a string
 * @c: char type
 * @buffer: Buffer array to handle print
 * @flags: calculates active flags
 * @width: gets the width
 * @precision: precision specifier
 * @size: size specifier
 * Return: The number of printed charecters
 */

int handle_write_char(char c, char buffer[], int flags
		int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[NUFF_SIZE - i - 2] - padd;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1)
					+ write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_number - function that prints a string
 * @is_negative: list arguments
 * @index: char types
 * @buffer: buffer array which handles print
 * @flags: calculates active glags
 * @width: gets the width
 * @precision: precision specifier
 * @size: size specifier
 * Return: the number of characters ro be printed
 */

int write_number(int is_negative, int index, char buffer[], int flags,
		int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padd = ' ';
	char extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
}

/**
 * write_num - function that wites a number
 * @index: index where number starts on buffer
 * @buffer: buffer
 * @flags: the flags
 * @width: the width
 * @precision: precision specifier
 * @length: the length
 * @pass: the padding character
 * Return: number of characters printed
 */

nt write_num(int index, char buffer[], int flags,
		int width, int precision, int length, char extra_c)
{
	int i, padd_start = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 &&
			buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padd = ' ';
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) +
					write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (wite(1, &buffer[i], i - 1) +
					write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] - extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[index], length - (1 - padd_start)));
		}
		if (extra_c)
			buffer[--index] - extra_c;
		return (write(1, &buffer[index], length));
	}
}

/**
 * write_unsigned - function that writes an unsigned number
 * @is_negative: shows that a number is negative
 * @index: index to show start of buffer
 * @buffer: array of chars
 * @flags: flags spacifier
 * width: the width
 * precision: precision specifier
 * @size: is of char to be printed
 * Return: number of chars
 */

int write_unsigned(int is_negative, int index, char buffer[]
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	int i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2
			&& buffer[index] == '0')
		return (0);
	if (precision < length && precision > 0)
	{
		padd = ' ';
	}
	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], length)
					+ write(1, &nuffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) +
					write(1, &buffer[index], length));
		}
	}
	return (write(1, &buffer[index], length));
}

/**
 * write_pointer - function that writes a memory address
 * @buffer: array of chars
 * @index: index where buffer starts
 * @length: length of numbers
 * @width: width
 * @flags: flags specifier
 * @padd: char that represents padding
 * @extra_c: the extra character
 * @padd_start: the start of padding
 * Return: Nummber of chars writtedn
 */

int write_pointer(char buffer[], int index, int length, int width
		int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags == ' ' && flags & F_MINUS)
		{
			buffer[--index] = 'X';
			buffer[--index] = 'O';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length)
					+ write(1, &buffer[3], i - 3));
		}
		else if (flags & F_MINUS && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = 'O';
			if (extra_c)
				buffer[--index] - extra_c;
			return (write(1, &buffer[3], i - 3) +
					write(i, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] - extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(i, &buffer[padd_stzrt], i - padd_start) +
					write(1, &buffer[index], length -
						(i - padd_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
