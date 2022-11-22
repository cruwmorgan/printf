#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
* p_ident - prints the special characters
* @m: a character
* @arg: an argument
* Return: the number of characters printed
*/

int p_ident(char m, va_list arg)
{
	int g;

	identifierStruct functs[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"r", print_reverse},
		{NULL, NULL}
	};
	/*@for loops through the arguments*/
	for (g = 0; functs[g].indentifier != NULL; g++)
	{
		if (functs[g].indentifier[0] == m)
			return (functs[g].printer(arg));
	}
	return (0);
}

/**
* _printf - function that produces output according to a format.
* @format: a pointer to a character
* @...: other arguments
* Description: produces output according to a format
* Return: the output
*/

int _printf(const char *format, ...)
{
	unsigned int j;
	int ident_p, char_p = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);
	/*@for loops through the other arguments*/
	for (j = 0; format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			putchar(format[j]);
			char_p++;
			continue;
		}
		if (format[j + 1] == '%')
		{
			putchar('%');
			char_p++;
			j++;
			continue;
		}
		if (format[j + 1] == '\0')
			return (-1);
		ident_p = p_ident(format[j + 1], arg);
		if (ident_p == -1 || ident_p != 0)
			j++;
		if (ident_p > 0)
			char_p += ident_p;
		if (ident_p == 0)
		{
			putchar('%');
			char_p++;
		}
	}
	va_end(arg);
	return (char_p);
}
