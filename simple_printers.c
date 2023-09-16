#include "main.h"

/**
 * print_from_to - Prints a range of characters from start to stop (excluding except).
 * @start: Starting address.
 * @stop: Stopping address.
 * @except: Except address (characters at this address will not be printed).
 *
 * Return: Number of bytes printed.
 */
int print_from_to(char *start, char *stop, char *except)
{
    int sum = 0;

    while (start <= stop)
    {
        if (start != except)
            sum += _putchar(*start);
        start++;
    }

    return (sum);
}

/**
 * print_rev - Prints a string in reverse.
 * @ap: String to print in reverse.
 * @params: The parameters struct (not currently used, marked as unused).
 *
 * Return: Number of bytes printed.
 */
int print_rev(va_list ap, params_t *params)
{
    int len, sum = 0;
    char *str = va_arg(ap, char *);
    (void)params; // Marked as unused to avoid compilation warnings.

    if (str)
    {
        for (len = 0; str[len]; len++) // Calculate the length of the string.
            continue;

        for (len--; len >= 0; len--) // Print characters in reverse order.
            sum += _putchar(str[len]);
    }

    return (sum);
}

/**
 * print_rot13 - Prints a string in ROT13 encoding.
 * @ap: String to print in ROT13.
 * @params: The parameters struct (not currently used, marked as unused).
 *
 * Return: Number of bytes printed.
 */
int print_rot13(va_list ap, params_t *params)
{
    int i, index;
    int count = 0;
    char arr[] =
        "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
    char *input = va_arg(ap, char *);
    (void)params; // Marked as unused to avoid compilation warnings.

    i = 0;
    index = 0;

    while (input[i])
    {
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
        {
            index = input[i] - 65;
            count += _putchar(arr[index]);
        }
        else
        {
            count += _putchar(input[i]);
        }
        i++;
    }

    return (count);
}

