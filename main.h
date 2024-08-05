#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdaef.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - the struct op
 * @fmt: The format
 * @a: The function associated
 */

struct format
{
	char fmt;
	int (*a)(va_list, char[], int, int, int, int);
};
int get_flags(const char *format. int *i0);
int get_width(const *format. int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size);
int write_number(int is_pos, int index, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int index, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int index, int length, int width,
		int flags, char padd, char extra_c, int padd_start);

int write_insgnd(int is_negative, int index, char buffer[],
		intflags, int width, int precision, int size);
int is_printable(char);
int append_hexa(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
#endif
