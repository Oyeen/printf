#include "main.h"
#include <limits.h>
#include <stdio.h>


/**
 * main - entry point
 *
 * Return: Always 0;
 */

int main(void)
{
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Percent:[%%]\n");
	printf("Percent:[%%]\n");

	return (0);
}
