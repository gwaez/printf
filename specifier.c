#include "main.h"

/**
 * get_specifier - Find the format function associated with a specifier.
 * @s: The format string.
 *
 * Return: A pointer to the corresponding format function or NULL if not found.
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
    specifier_t specifiers[] = {
        {"c", print_char},
        {"d", print_int},
        {"i", print_int},
        {"s", print_string},
        {"%", print_percent},
        {"b", print_binary},
        {"o", print_octal},
        {"u", print_unsigned},
        {"x", print_hex},
        {"X", print_HEX},
        {"p", print_address},
        {"S", print_S},
        {"r", print_rev},
        {"R", print_rot13},
        {NULL, NULL}
    };

    for (int i = 0; specifiers[i].specifier != NULL; i++)
    {
        if (*s == specifiers[i].specifier[0])
        {
            return (specifiers[i].f);
        }
    }

    return (NULL);
}

/**
 * get_print_func - Find the format function based on the specifier.
 * @s: The format string.
 * @ap: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: The format function to be used or 0 if not found.
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
    int (*f)(va_list, params_t *) = get_specifier(s);

    if (f)
    {
        return (f(ap, params));
    }
    
    return (0);
}

/**
 * get_flag - Check if a character is a valid flag.
 * @s: The format string.
 * @params: The parameters struct.
 *
 * Return: 1 if the character is a valid flag, 0 otherwise.
 */
int get_flag(char *s, params_t *params)
{
    switch (*s)
    {
    case '+':
        return (params->plus_flag = 1);
    case ' ':
        return (params->space_flag = 1);
    case '#':
        return (params->hashtag_flag = 1);
    case '-':
        return (params->minus_flag = 1);
    case '0':
        return (params->zero_flag = 1);
    default:
        return 0;
    }
}

/**
 * get_modifier - Check if a character is a valid modifier.
 * @s: The format string.
 * @params: The parameters struct.
 *
 * Return: 1 if the character is a valid modifier, 0 otherwise.
 */
int get_modifier(char *s, params_t *params)
{
    switch (*s)
    {
    case 'h':
        return (params->h_modifier = 1);
    case 'l':
        return (params->l_modifier = 1);
    default:
        return 0;
    }
}

/**
 * get_width - Get the width from the format string.
 * @s: The format string.
 * @params: The parameters struct.
 * @ap: The argument pointer.
 *
 * Return: A new pointer after parsing the width specification.
 */
char *get_width(char *s, params_t *params, va_list ap)
{
    int d = 0;

    if (*s == '*')
    {
        d = va_arg(ap, int);
        s++;
    }
    else
    {
        while (_isdigit(*s))
        {
            d = d * 10 + (*s - '0');
            s++;
        }
    }

    params->width = d;
    return s;
}

