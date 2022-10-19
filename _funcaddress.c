#include "main.h"

/**
 * _funcaddress - print address of input in hexadcimal
 * @l: va_list args
 * @f: pointer of struct flags that checks
 * flags passed to _printf
 *
 * Return: count
 */
int _funcaddress(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));
	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
