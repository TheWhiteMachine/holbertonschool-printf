#ifndef _theprintf
#define _theprintf


#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int _putchar(char c);
int _printf(const char *format, ...);



/**
* struct ops - Struct options
* @option: Options
* @f: Function asociated
*/

typedef struct ops
{
		char *option;
		int (*get_func)();
} opc_t;


int read_string( const char *format, opc_t[], va_list args);
int func_c(va_list args);
int func_s(va_list args);
int func_percent(__attribute__((unused))va_list args);
int func_i(va_list args);
int func_d(va_list args);


#endif
