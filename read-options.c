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
	/* start reading formated stirng*/
	for (i = 0; format[i] != '\0'; i++)
	{

		/*find a % and after there arent a blank*/
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
		/*search the letter after % to find coincidence in option list*/
			for (j = 0; opt_list[j].option != NULL; j++)
			{
				/*find a coincidence option*/
				if (format[i + 1] == opt_list[j].option[0])
				{
					/*call the function nnd add characters*/
					error_c = opt_list[j].get_func(args);
					if (error_c > 0)
					{
						/*copy character cout of function */
						c_func = error_c;
					/* pass to next character on formated sring**/
					i++;
					}
					break;
				}
			}
			c_count += c_func;
			/*no coincidence at the option list, print any and count */
			if (opt_list[j].option == NULL)
				c_count += _putchar(format[i]);

		}
		else
		{
			/*find a character difrent to % and print it  DIRECT PRINT*/
			c_count += _putchar(format[i]);
		}

	}
	return (c_count);
}
