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
		return (-2);

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

	str = va_arg(args, char*);
	if (str != NULL)
	{

		for (c = 0; str[c] != '\0'; c++)
		{
			_putchar(str[c]);
		}
	}
	else
	{
		write (1,"(null)", 6);
		return (6);
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
	int i = 0;
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
	return (c_count -1);
}

