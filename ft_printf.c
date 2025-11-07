/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:17:21 by lpaiva            #+#    #+#             */
/*   Updated: 2025/11/07 02:31:25 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// simulation of printf
#include "libprint.h"
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	
}
// int	ft_printf(const char *, ...);
/* 
int ft_putptr(unsigned long long ptr,  int count)
{
	if(ptr == 0)
		return ft_putsr_fd("(nil)", 1);
	count += ft_putstr_fd("0x", 1);
	count +
} */

int	ft_putnbr_bas_fd(long long nb,char *base, int base_len, int fd, int count)
{
	char	buffer[65];
	int		i;
	
	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	i = 0;
	while (nb > 0)
	{
		buffer[i++] = base[nb % base_len];
		nb /= base_len;
	}
	while (i > 0)
	{
		ft_putchar_fd(buffer[--i], fd);
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	long int	num;
	char		digit;
	int			count;

	num = nb;
	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}
	if (num / 10 != 0)
	{
		ft_putnbr(num / 10);
		count++;
	}	
	digit = (num % 10) + '0';
	write(1, &digit, 1);
	return (count);
}


int	ft_putstr_fd(char *s, int fd)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

int	format_handle(char flag, va_list args, int count)
{
	if(flag == 'c')
	{
		ft_putchar_fd(va_arg(args,int), 1);
		count++;
	}else if(flag == 's')
		count = ft_putstr_fd(va_arg(args, char *), 1);
	else if (flag == 'p')
		count = ft_putptr(va_arg(args, long long), count);
	else if (flag == 'd' || flag == 'i')
		count = ft_putnbr(va_arg(args,int));		
	
	return (count);	
}

int	ft_printf(const char *format, ...)
{
	va_list	args; //va_list is: 
	int		i; //iteraação da str
	int		count;// cararters escritos ptr printf

	va_start(args, format); // começo da lista de argumentos
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count = format_handle(format[i], args, count);
		}else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
		return (0);
	}
	return (count);
}
