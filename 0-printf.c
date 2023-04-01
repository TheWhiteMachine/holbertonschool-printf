#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>
/**
 * _printf - print varius formats of data
 * @format: a formated string to print
 */

int _printf(const char *format, ...)
{
	int printed = 0;
	int error = 0;
	va_list args;

	opc_t opt_list[] = {
	{"c", func_c},
	{"s", func_s},
	{"%", func_percent},
	{"i", func_i},
	{"d", func_i},
	{NULL, NULL},
	};

	if (!format)
	{
		return (-1);
	}

	va_start(args, format);
	error =  read_string(format, opt_list, args);

	if (error == -1)
		return (1);
	if (error == -2)
		return (1);
	if (error == -3)
		return (-1);
	if (error == -4)
		return (0);
	if (error == 0)
		return (1);
	if (error > 0)
		printed = error;

	va_end(args);

	return (printed);
}
