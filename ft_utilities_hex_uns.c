/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_hex_uns.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:42:28 by lpaiva            #+#    #+#             */
/*   Updated: 2025/11/10 18:40:33 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// utilitis for printf
// inludes the "the flags" --
// '%x' && '&X'  && '%u' -- ft_putnbr_base_uns
//  for unsignd int and hexadecimal numbers and pointrs
#include "ft_printf.h"

int	ft_putnbr_base_uns(unsigned long long nbr, char *base, int base_len,
		int count)
{
	if (nbr >= (unsigned long long)base_len)
		count = ft_putnbr_base_uns(nbr / base_len, base, base_len, count);
	count = ft_putchar(base[nbr % base_len], count);
	return (count);
}

int	ft_ptptr(void *ptr, int count)
{
	unsigned long long	point;

	point = (unsigned long long)ptr;
	if (point == 0)
		return (ft_putstr("(nil)", count));
	count = ft_putstr("0x", count);
	count = ft_putnbr_base_uns(point, "0123456789abcdef", 16, count);
	return (count);
}
