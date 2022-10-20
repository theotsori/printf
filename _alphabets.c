/*
 * File: _alphabets.c
 * Auth: Theodore Tsori
 *       Aryton Koskei
 */

#include "main.h"

/**
 * _funstr - prints strings
 * @l: va_list args
 * @f: ptr that confirms flags to
 * be passed to _printf
 * Return: string
 */
int _funstr(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * _funchar - prints char
 * @l: va_list args
 * @f: ptr tat confirm flags to be
 * passed to _putchar
 *
 * Return: len char
 */
int _funchar(va_list l, flags_t *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);
}
