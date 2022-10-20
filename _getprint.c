/*
 * File: _getprint.c
 * Auth: Theodore Tsori
 *       Aryton Koskei
 */

#include "main.h"

/**
 * get_print - selects the correct function to print
 * and sends it to _printf
 * @s: char
 *
 * Return: pointer matching print function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', _funint},
		{'s', _funstr},
		{'c', _funchar},
		{'d', _funint},
		{'u', _funsigned},
		{'x', _funhex},
		{'X', _funhextra},
		{'b', _funbin},
		{'o', _funoctal},
		{'R', _funrot13},
		{'r', _funcrev},
		{'S', _funS},
		{'p', _funcaddress},
		{'%', _funcent}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
