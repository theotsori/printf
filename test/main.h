#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to activate
 * when they are sent to _printf function
 *
 * @plus: flag for '+'
 * @space: flag for ' '
 * @hash: flag for '#'
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printMng - chooses function to
 * be sent to _printf function
 *
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printMng
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* _funums */
int _funint(va_list l, flags_t *f);
void _funumber(int n);
int _funsigned(va_list l, flags_t *f);
int _digitcount(int i);

/* base.c */
int _funhex(va_list l, flags_t *f);
int _funhextra(va_list l, flags_t *f);
int _funbin(va_list l, flags_t *f);
int _funoctal(va_list l, flags_t *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

int (*get_print(char s))(va_list, flags_t *);

int get_flag(char s, flags_t *f);

/* _alpahbet.c */
int _funstr(va_list l, flags_t *f);
int _funchar(va_list l, flags_t *f);

/* _putchar.c */
int _putchar(char c);
int _puts(char *str);

/* rot13 */
int _funrot13(va_list l, flags_t *f);
int _funcrev(va_list l, flags_t *f);
int _funS(va_list l, flags_t *f);

int _funcaddress(va_list l, flags_t *f);
int _funcent(va_list l, flags_t *f);

#endif
