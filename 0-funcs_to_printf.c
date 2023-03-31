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
		return(-2);

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
	{
		write(1,"(null)",6);
		return(6);
	}


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

	long int numarg = va_arg(args, int);
	int i =0;
	int c_count = 0;
	long int num = 0;
	long int acc = 0;

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
	int error_c = 0;
/* start reading formated stirng*/
	for (i = 0; format[i] != '\0'; i++)
	{
		/* case to find a % and theres a letter after*/
		if (format[i] == '%' && format[i + 1] != ' ')
		{
			/*if a & sing is the last character not to print and return an error*/
			if (format[i + 1] == '\0')
				return (-1);
			/*search the letter after % to find coincidence in option list*/
			for (j = 0; opt_list[j].option != NULL; j++)
			{
				/*find a coincidence option*/
				if (format[i + 1] == opt_list[j].option[0])
				{
					/*call the function execute it and sum the characters printed*/
					error_c = opt_list[j].get_func(args);
					if (error_c > 0)
					{
						/*copy character cout of function in c_func knowing that dont have errors reported*/
						c_func = error_c;
						/* pas to next character on formated sring*/
						i++;
					}
					break;
				}
			}

			c_count += c_func;
			/*no coincidence at the option list, print any other character* DIRECT PRINT*/
			if (opt_list[j].option == NULL)
			{
				c_count += _putchar(format[i]);
			}
		}
		else
		{
			/*find a character difrent to % and print it  DIRECT PRINT*/
			c_count += _putchar(format[i]);
		}
	}
	/* take the printed charracters for functions and the direct print and join them*/

	return (c_count);
}
