#include "main.h"

/**
 * get_precision - Extracts the precision from the format string.
 * @p: The format string.
 * @params: The parameters struct.
 * @ap: The argument pointer.
 *
 * Return: A new pointer after parsing the precision specification.
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
    int d = 0;

    if (*p != '.')
    {
        return p; // No precision specification found, return as-is.
    }

    p++; // Move past the period '.'

    if (*p == '*')
    {
        d = va_arg(ap, int);
        p++;
    }
    else
    {
        while (_isdigit(*p))
        {
            d = d * 10 + (*p - '0');
            p++;
        }
    }

    params->precision = d;
    return p;
}

