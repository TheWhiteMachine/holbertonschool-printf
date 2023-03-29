#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>
/**
 * _printf - print varius formats of data
 * @format: a list of formats to print
 */

int func_c(va_list args)
{
	char c;

	c = va_arg(args, int);

	if (c != '\0')
	{
		_putchar(c);
	}
	else
		return (-1);

	return (1);
}


int func_s(va_list args)
{
	char *str;
	int c_count;

	str = va_arg(args, char*);
	if (str != NULL)
	{

		for (c_count = 0; str[c_count] != '\0'; c_count++)
		{
			_putchar(str[c_count]);
		}
	}

	return (c_count);
}


int func_percent(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}
/*
int func_i(va_list args)
{
	int i = 1;
	int c_count = 0;
	int cifras,;
	int cifra;
	
	number = va_arg(args, int);

	cifras = number;
	if (number >= 0)
	{
	while( num / 10 > 1 )
	{
		cifras /= 10;
		i++
	}

	for (; i == 0; i--)
	{
		numbers += number % 10;
		number /= 10;
		numbers *= 10;
	}


	
	
		c_count++;
	
	}


	return(c_count);
}
*/
int read_string(const char *format, opc_t opt_list[], va_list args)
{
	int i, j;
	int c_count;
	int total = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; opt_list[j].option != NULL; j++)
			{

				if (format[i + 1] == opt_list[j].option[0])
				{
					c_count = opt_list[j].get_func(args);
					if (c_count == -1)
					{
						return (-1);
					}
					else
						i++;
					total += c_count;
					break;
				}
			}
			if (opt_list[j].option == NULL)
			{
				_putchar(format[i]);
				total++;
			}
		}
		else
		{
			_putchar(format[i]);
			total++;
		}
	}
	return (total);


}
int _printf(const char *format, ...)
{
	int printed;

	va_list args;

	opc_t opt_list[] = {
	{"c", func_c},
	{"s", func_s},
	{"%", func_percent},
	{NULL, NULL},
	};

	if (!format)
	{
		return (-1);
	}

	va_start(args, format);
	printed = read_string(format, opt_list, args);
	va_end(args);

	return (printed);


}
