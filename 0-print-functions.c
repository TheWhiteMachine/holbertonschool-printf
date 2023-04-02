#include "main.h"
/**
 * func_c - print a char
 * @args: list of printf args
 * Return: 1 per cahr and -2 on null
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
 * Return: number of printed chars (null) on NULL
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
		write(1, "(null)", 6);
		return (6);
	}

	return (c);
}


/**
 * func_percent - print a percetn sign
 * @args: list of printf args
 * Return: 1;
 */

int func_percent(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}


/**
 * func_i - print a int number
 * @args: int args of printf
 * Return: number of printed digits
 */

int func_i(va_list args)
{
	long int num = va_arg(args, int);

	int long digits = 1;

	int c_count = 0;

	if (!num)
	{
		_putchar('0');
		return (0);
	}
	if (num == 0)
		return (0);

	if (num < 0)
	{
		_putchar('-');
		c_count += 1;
		num *= -1;
	}
	for (; digits <= num; digits *= 10)
		c_count++;

	digits /= 10;

	for (; digits > 0; digits /= 10)
		_putchar(((num / digits) % 10) + '0');

	return (c_count);
}

