/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:16:32 by mlangloi          #+#    #+#             */
/*   Updated: 2023/04/18 13:24:39 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_format(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(arg, int));
	else if (format == 's')
		len += ft_printstr(va_arg(arg, char *));
	else if (format == 'p')
		len += ft_printptr(va_arg(arg, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(arg, int));
	else if (format == 'u')
		len += ft_printunsigned(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_printhex(va_arg(arg, unsigned int), format);
	else if (format == '%')
		len += ft_printpercent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;
	int		len;

	i = 0;
	len = 0;
	va_start (arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(arg, format[i + 1]);
			i++;
		}
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
