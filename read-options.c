#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>

/**
 * read_string - read format and choose function to execute
 * @format: text and modificators to printf
 * @opt_list: a structur with options and pointers to functions
 * @args: va_list of arguments of printf
 * Return: count of characters
 */

int read_string(const char *format, opc_t opt_list[], va_list args)
{
	int i, j;
	int c_count = 0;
	int c_func = 0;
	int error_c = 0;

	for (i = 0; format[i] != '\0'; i++)
	{

		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			for (j = 0; opt_list[j].option != NULL; j++)
			{
					error_c = opt_list[j].get_func(args);
					if (error_c > 0)
					{
						c_func = error_c;
					i++;
					}
					break;
				}
			}
			c_count += c_func;
			if (opt_list[j].option == NULL)
				c_count += _putchar(format[i]);

		}
		else
		{
			c_count += _putchar(format[i]);
		}

	}
	return (c_count);
}
