/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:26:27 by lpaiva            #+#    #+#             */
/*   Updated: 2025/11/11 19:18:07 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implementacion of printf function of c libary
#include "ft_printf.h"

int	format_handle(char flag, va_list args, int count)
{
	if (flag == 'c')
		count = ft_putchar(va_arg(args, int), count);
	else if (flag == 's')
		count = ft_putstr(va_arg(args, char *), count);
	else if (flag == 'd' || flag == 'i')
		count = ft_putnbr_base((long long)va_arg(args, int), "0123456789", 10,
				count);
	else if (flag == 'u')
		count = ft_putnbr_base_uns((unsigned long long)va_arg(args,
					unsigned int), "0123456789", 10, count);
	else if (flag == 'x')
		count = ft_putnbr_base_uns((unsigned long long)va_arg(args,
					unsigned int), "0123456789abcdef", 16, count);
	else if (flag == 'X')
		count = ft_putnbr_base_uns((unsigned long long)va_arg(args,
					unsigned int), "0123456789ABCDEF", 16, count);
	else if (flag == 'p')
		count = ft_ptptr(va_arg(args, void *), count);
	else if (flag == '%')
		count = ft_putchar('%', count);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			count;

	va_start(args, format);
	if (!format)
	{
		count = -1;
		return (count);
	}	
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count = format_handle(format[++i], args, count);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}