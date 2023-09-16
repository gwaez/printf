#include "main.h"

/**
 * init_params - Initialize and reset the fields of the params_t struct
 * @params: Pointer to the parameters struct to be initialized
 * @ap: The argument pointer (not currently used, so marked as unused)
 *
 * This function initializes all fields of the params_t struct to their default
 * values.
 */
void init_params(params_t *params, va_list ap)
{
    // Clear all flags and set numeric fields to default values
    params->unsign = 0;

    params->plus_flag = 0;
    params->space_flag = 0;
    params->hashtag_flag = 0;
    params->zero_flag = 0;
    params->minus_flag = 0;

    params->width = 0;
    params->precision = UINT_MAX;

    // Clear modifier flags
    params->h_modifier = 0;
    params->l_modifier = 0;

    // Mark the 'ap' parameter as unused to avoid compilation warnings
    (void)ap;
}

