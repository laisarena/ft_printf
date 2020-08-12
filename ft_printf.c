#include "libftprintf.h"

typedef	struct
{
	int	flag;
	int	width;
	int	precision;
	int	length;
	int	specifier;
}	t_speci;

int	ft_checkflag(char c)
{
	if (c == '-')
		return ('-');
	if (c == '+')
		return ('+');
	if (c == ' ')
		return (' ');
	if (c == '#')
		return ('#');
	if (c == '0')
		return ('0');
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{	
		}
		else
			ft_putchar_fd(*format, 1);
	format++;
	}	
	va_end(args);
	return (0);
}
