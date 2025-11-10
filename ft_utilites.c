/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:33:41 by lpaiva            #+#    #+#             */
/*   Updated: 2025/11/10 18:40:45 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// utilitis for printf
// inludes the "the flags" --
// '%c' -- ft_putchar fuction
// '%s' -- ft_putstr funciton
// '%d' && '%i' -- ft_putnbr_base
#include "ft_printf.h"

int	ft_putchar(char c, int count)
{
	write(1, &c, 1);
	return (++count);
}

int	ft_putstr(char *str, int count)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		count = ft_putchar(str[i++], count);
	return (count);
}

int	ft_putnbr_base(long long nbr, char *base, int base_len, int count)
{
	char	buffer[65];
	int		i;

	if (nbr == 0)
		return (ft_putchar('0', count));
	if (nbr < 0)
	{
		count = ft_putchar('-', count);
		nbr = -nbr;
	}
	i = 0;
	while (nbr > 0)
	{
		buffer[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	while (i > 0)
	{
		count = ft_putchar(buffer[--i], count);
	}
	return (count);
}
