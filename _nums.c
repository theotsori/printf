#include "main.h"

/**
 * _funint - prints an integer
 * @l: va_list of args
 * @f: ptr
 *
 * Return: number of char printed
 */
int _funint(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int res = _digitcount(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	_funumber(n);
	return (res);
}

/**
 * _funsigned - prints an unsigned integer
 * @l: va_list of args
 * @f: ptr
 *
 * Return: number of char printed
 */
int _funsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = convert(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * _funumber - prints numbers
 * @n: integer to be printed
 */
void _funumber(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		_funumber(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * _digitcount - return number of digits in an integer
 *
 * @i: evaluates integer
 * Return: number of digits
 */
int _digitcount(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
