#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
* print_char - writes a character to stdout
* @arg: an argument
* Return: 0 is returned
*/

int print_char(va_list arg)
{
	return (putchar(va_arg(arg, int)));
}

/**
* print_str - prints a string in lowercase
* @arg: an argument
* Return: the number of printed characters
*/

int print_str(va_list arg)
{
	int m;
	char *s = va_arg(arg, char*);
	/*@if checks for null*/
	if (s == NULL)
		s = "(null)";
	else if (*s == '\0')
		return (-1);
	for (m = 0; s[m]; m++)
		putchar(s[m]);
	return (m);
}

/**
* print_int - prints an integer.
* @arg: an argument
* Return: 0 is returned
*/

int print_int(va_list arg)
{
	unsigned int divisor = 1, i, resp, charPrinted = 0;
	int n = va_arg(arg, int);

	/*@if checks for null*/
	if (n < 0)
	{
		putchar('-');
		charPrinted++;
		n *= -1;
	}
	for (i = 0; n / divisor > 9; i++, divisor *= 10)
	;
	for (; divisor >= 1; n %= divisor, divisor /= 10, charPrinted++)
	{
		resp = n / divisor;
		putchar('0' + resp);
	}
	return (charPrinted);
}
