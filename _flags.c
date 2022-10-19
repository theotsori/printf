#include "main.h"

/**
 * get_flag - turns flags on when _printf gets
 * flag modifier
 * @s: char
 * @f: ptr
 *
 * Return: 1 else 0
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
