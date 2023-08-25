#include "main.h"
/**
 * get_conversion - retrieves the conversion func for a given format specifier
 * @format: format string
 * @i: the pointer to the current index in the format string
 * @args: va_list of arguments
 * @flags: the pointer to a flags_t struct containing any flags found
 * @width: the pointer to a width_t struct containing any widths found
 * Return: the pointer to the conversion function
 */

pfn_t get_conversion(const char *format, int *i, va_list args,
					 flags_t *flags, width_t *width)
{
	int (*pfn)(va_list);

	get_flags(format, flags, i);
	get_width(format, width, i);
	get_length(format, flags, i);

	if (width->is_astreak)
		width->value = va_arg(args, int);
	pfn = get_print(&format[*i]);
	return (pfn);
}
