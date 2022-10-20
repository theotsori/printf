/*
 * File: _rot13.c
 * Auth: Theodore Tsori
 *       Aryton Koskei
 */

#include "main.h"

/**
 * _funS - unprintable characters
 * @l: va_list args
 * @f: ptr that confirms what is passed to _printf
 *
 * Description: function calls 'convert()' which converts input
 * to the correct base
 * Return: count
 */
int _funS(va_list l, flags_t *f)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}

/**
 * _funcrev - prints a string in reverse
 * @l: args from _printf
 * @f: ptr to the struct
 *
 * Return: len string
 */
int _funcrev(va_list l, flags_t *f)
{
	int i = 0, j;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}

/**
 * _funrot13 - encrypts using rot13
 * @l: arguments from _printf
 * @f: ptr to _printf
 * Return: ptr to rot13
 */
int _funrot13(va_list l, flags_t *f)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);

	(void)f;
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}

/**
 * _funcent - prints a percent
 * @l: va_list arguments for _printf
 * @f: ptr of flags
 * Return: num of char to be printed
 */
int _funcent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}
