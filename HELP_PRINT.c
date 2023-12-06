#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @handleob: string format.
 * @ind: the end
 * @buffer: a memory to handle printing array
 * @flags: calculating flags
 * @width: get width.
 * @precision: percise
 * @countlist: counting the list
 * @size: Get Size
 * Return: 1 or 2;
 */
int handle_print(const char *handleob, int *ind, va_list countlist
, char buffer[], int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	handle_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].handleob != '\0'; i++)
		if (handleob[*ind] == fmt_types[i].handleob)
			return (fmt_types[i].fn(countlist, buffer, flags, width, precision, size));

	if (fmt_types[i].handleob == '\0')
	{
		if (handleob[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (handleob[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (handleob[*ind] != ' ' && handleob[*ind] != '%')
				--(*ind);
			if (handleob[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &handleob[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

