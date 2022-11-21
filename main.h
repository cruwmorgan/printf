#ifndef MAIN_H
#define MAIN_H

/**
* struct identifierStruct - structure definition of a printTypeStruct
* @indentifier: type
* @printer: function to print
*/

typedef struct identifierStruct
{
	char *indentifier;
	int (*printer)(va_list);

} identifierStruct;

int p_ident(char m, va_list arg);
int _printf(const char *format, ...);
#endif /*MAIN_H*/
