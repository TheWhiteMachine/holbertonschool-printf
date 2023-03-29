#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
 /*   int len;
    int len2;

    void *addr; 

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("%d, %i",len, len);
	printf("%d, %i", len2, len2);
	*/
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("[%c]\n", 'H');
	printf("[%c]\n", 'H');
	_printf("Percent:[%%]");
	return (0);
}
