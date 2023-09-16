#include "main.h"

/**
 * convert - Converts a number to a string with the specified base.
 * @num: The number to convert.
 * @base: The base for conversion (e.g., 10 for decimal, 16 for hexadecimal).
 * @flags: Argument flags (e.g., CONVERT_UNSIGNED).
 * @params: Parameter struct (not currently used, marked as unused).
 *
 * Return: The converted string.
 */
char *convert(long int num, int base, int flags, params_t *params)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;
    (void)params; // Marked as unused to avoid compilation warnings.

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }

    array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;

    return ptr;
}

/**
 * print_unsigned - Prints unsigned integer numbers.
 * @ap: Argument pointer.
 * @params: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int print_unsigned(va_list ap, params_t *params)
{
    unsigned long l;

    if (params->l_modifier)
        l = va_arg(ap, unsigned long);
    else if (params->h_modifier)
        l = va_arg(ap, unsigned int);
    else
        l = va_arg(ap, unsigned int);

    params->unsign = 1;
    return print_number(convert(l, 10, CONVERT_UNSIGNED, params), params);
}

/**
 * print_address - Prints an address.
 * @ap: Argument pointer.
 * @params: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int print_address(va_list ap, params_t *params)
{
    unsigned long int n = va_arg(ap, unsigned long int);
    char *str;

    if (!n)
        return _puts("(nil)");

    str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
    *--str = 'x';
    *--str = '0';
    return print_number(str, params);
}

