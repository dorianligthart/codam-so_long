/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:44:30 by dligthar          #+#    #+#             */
/*   Updated: 2024/03/15 17:13:45 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> //NULL, 'size_t'
#include <stdarg.h> //va_list, va_start(), va_arg(), va_end(), '...'
#include <unistd.h> //write(), 'ssize_t'
#include <limits.h> //INT_MIN
#include "libft.h"

static int	pf_write_unsigned(int fd, size_t nbr, char *basestr)
{
	size_t	divider;
	int		base;
	int		i;
	char	put[31];

	base = 0;
	while (basestr && basestr[base])
		base++;
	if (base < 2)
		return (ERROR_LIBFT);
	divider = 1;
	while (divider <= nbr / base)
		divider = divider * base;
	i = 0;
	while (divider)
	{
		put[i] = basestr[nbr / divider];
		nbr = nbr % divider;
		divider = divider / base;
		i++;
	}
	put[i] = '\0';
	return (write(fd, put, i));
}

static int	pf_write_signed(int fd, va_list *list)
{
	int	ret2;
	int	ret;
	int	integer;

	ret = 0;
	integer = va_arg(*list, int);
	if (integer == INT_MIN)
		return (write(fd, "-2147483648", 11));
	if (integer < 0)
	{
		ret = write(fd, "-", 1);
		integer *= -1;
	}
	ret2 = pf_write_unsigned(fd, integer, "0123456789");
	if (ret < 0 || ret2 < 0)
		return (-1);
	return (ret + ret2);
}

static int	pf_choose_unsigned(int fd, va_list *list, char conversion)
{
	int				ret;
	int				ret2;
	void			*p_conv;
	unsigned int	uinteger;

	if (conversion == 'p')
	{
		p_conv = va_arg(*list, void *);
		if (p_conv == (void *)0)
			return (write(fd, "(nil)", 5));
		ret = write(fd, "0x", 2);
		ret2 = pf_write_unsigned(fd, (size_t)p_conv, "0123456789abcdef");
		if (ret < 0 || ret2 < 0)
			return (ERROR_LIBFT);
		return (ret + ret2);
	}
	else
		uinteger = va_arg(*list, unsigned int);
	if (conversion == 'u')
		return (pf_write_unsigned(fd, (size_t)uinteger, "0123456789"));
	else if (conversion == 'x')
		return (pf_write_unsigned(fd, (size_t)uinteger, "0123456789abcdef"));
	else if (conversion == 'X')
		return (pf_write_unsigned(fd, (size_t)uinteger, "0123456789ABCDEF"));
	return (0);
}

static int	pf_newformat(int fd, va_list *list, const char **s)
{
	char	*string;
	int		i;

	if (**s == '%' && ++*s)
		return (write(fd, "%", 1));
	if (**s == 'c' && ++*s)
	{
		i = va_arg(*list, int);
		return (write(fd, &i, 1));
	}
	if (**s == 's' && ++*s)
	{
		string = va_arg(*list, char *);
		if (!string)
			return (write(fd, "(null)", 6));
		i = 0;
		while (string[i])
			i++;
		return (write(fd, string, i));
	}
	if ((**s == 'd' || **s == 'i') && ++*s)
		return (pf_write_signed(fd, list));
	if ((**s == 'u' || **s == 'x' || **s == 'X' || **s == 'p') && ++*s)
		return (pf_choose_unsigned(fd, list, *(*s - 1)));
	return (ERROR_LIBFT);
}

int	ft_printf(const char *format, ...)
{
	va_list		list;
	int			printed;
	int			x;
	int			y;
	const char	*tmp;

	if (!format)
		return (ERROR_LIBFT);
	va_start(list, format);
	printed = 0;
	while (*format)
	{
		tmp = format;
		while (*format && *format != '%')
			format++;
		x = write(1, tmp, format - tmp);
		y = 0;
		if (*format == '%' && format++)
			y = pf_newformat(1, &list, &format);
		if (x < 0 || y < 0)
			return (-1);
		printed = printed + x + y;
	}
	va_end(list);
	return ((int)printed);
}
