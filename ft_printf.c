#include "libftprintf.h"

typedef	struct
{
	int	width;
	int	precision;
}	t_flags;

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

void 	ft_c(va_list args)
{
	ft_putchar_fd(va_arg(args, int), 1);	
}

static int ft_isconversion (char c)
{
	if (c == 'c' || c == 's'|| c == 'p' || c == 'd' || c == 'i')
		return (1);
	return (0);
}

static int	ft_conversionposition(const char *s)
{
	int position;

	position = 0;
	while (!(ft_isconversion((char)s[position])))
		if (s[position++] == '\0')
			return (0);
	return (position);
}
	
int ft_printarg(const char *format, va_list args)
{
	int position;
	if (!(position = ft_conversionposition(format++)))
		return (0);
	ft_substr( format, 0, position);
	format += position - 1;
	if (*format == 'c')
		ft_c(args);
	if (*format == 's')
		return (0);
	if (*format == 'p')
		return (0);
	if (*format == 'd')
		return (0);
	if (*format == 'i')
		return (0);
	return(position);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int position;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if(!(position = ft_printarg(format, args)))
				return(0);
			format += position;
		}
		else
			ft_putchar_fd(*format, 1);
	format++;
	}	
	va_end(args);
	return (0);
}
