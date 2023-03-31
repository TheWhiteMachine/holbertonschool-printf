#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>

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
