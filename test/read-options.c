#include "main.h"

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

	if (format[0] == 0)
		return (-4);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-3);
			for (j = 0; opt_list[j].option != NULL; j++)
			{
				if (format[i + 1] == opt_list[j].option[0])
				{
					error_c = opt_list[j].get_func(args);
					if (error_c > 0)
					{
						c_func = error_c, i++;
					}
					else
						return (error_c);
				break;
				}
			}
			if (opt_list[j].option == NULL)
				c_count += _putchar(format[i]) / 2;

			c_count += c_func;
		}
		else
			c_count += _putchar(format[i]);
	}
	return (c_count);
}
