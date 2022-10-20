/*
 * File: _bases.c
 * Auth: Theodore Tsori
 *       Aryton Koskei
 */

#include "main.h"

/**
 * _funhex - print lowercase num in hexadecimal
 * @l: va_list args
 * @f: ptr that confirms what is passed to _printf
 *
 * Return: count
 */
int _funhex(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 1);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
 * _funhextra - prints uppercasenums in hexadecimal
 * @l: va_list args
 * @f: ptr that confirms what is passed to _printf
 *
 * Description: function calls 'convert()' which converts input
 * to the correct base
 * Return: count
 */
int _funhextra(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);
	return (count);
}

/**
 * _funbin - prints number to base 2
 * @l: va_list args
 * @f: ptr that confirms what is passed to _printf
 *
 * Description: function calls 'convert()' which converts input
 * to the correct base
 * Return: count
 */
int _funbin(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 2, 0);

	(void)f;
	return (_puts(str));
}

/**
 * _funoctal - prints  num t0 base 8
 * @l: va_list args
 * @f: ptr that confirms what is passed to _printf
 *
 * Description: function calls 'convert()' which converts input
 * to the correct base
 * Return: count
 */
int _funoctal(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 8, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}
