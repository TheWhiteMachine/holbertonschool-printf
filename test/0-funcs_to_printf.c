#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>
/**
 * _func_c - print a char
 * @args: list of printf args
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

/**
 * func_s - print a string
 * @args: list of printf args
 */
int func_s(va_list args)
{
	char *str;
	int c = 0;

	str = va_arg(args,char*);
	if (str != NULL)
	{

		for (c = 0; str[c] != '\0'; c++)
		{
			_putchar(str[c]);
		}
	}
	else
		return (-1);

	return (c);
}


/**
 * func_perenct - print a percetn sign
 * @args: list of printf args
 */

int func_percent(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}


/**
 * func_i - print a int number
 * @args: int args of printf
 */

int func_i(va_list args)
{

	int numarg = va_arg(args, int);
	int i =0;
	int c_count = 0;
	int num = 0;
	int acc = 0;

	if (!numarg)
		return (-1);

	if (numarg < 0)
	{
		_putchar('-');
		c_count += 1;
		numarg *= -1;
	}
	num = numarg;
	acc = num % 10;
	for (i = 1; num > 0; i++)
	{
		num /= 10;
		if  (num >= 0)
		{
			acc *= 10;
			acc += num % 10;
		}
		else
			acc += num;
	}
	_putchar(acc % 10);
	c_count++;
	for (; i > 1; i--)
	{
		acc /= 10;
		_putchar(acc % 10 + '0');
		c_count++;
	}
	return (c_count);
}



/**
 * read_string - read format and choose function to execute
 * @format: text and modificators to printf
 * @opt_list: a structur with options and pointers to functions
 * @args: va_list of arguments of printf
 */

int read_string (const char *format, opc_t opt_list[], va_list args)
{
	int i, j;
	int c_count = 0;
	int c_func = 0;
	

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != ' ')
		{
			for (j = 0; opt_list[j].option != NULL; j++)
			{

				if (format[i + 1] == opt_list[j].option[0])
				{
					c_func = opt_list[j].get_func(args);
					if (c_func == -1)
					{
						return (-1);
					}
					else
						i++;
					break;
				}
			}
			if (opt_list[j].option == NULL)
			{
				_putchar(format[i]);
				c_count += 1;
			}
		}
		else
		{
			_putchar(format[i]);
			c_count += 1;
		}
	}
	c_count += c_func;
	return (c_count);
}
