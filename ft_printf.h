/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:27:51 by lpaiva            #+#    #+#             */
/*   Updated: 2025/11/12 22:33:26 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c, int count);
int	ft_putstr(char *str, int count);
int	ft_printf(const char *format, ...);
int	ft_putnbr_base(long nbr, char *base, int base_len, int count);
int	ft_putnbr_base_uns(unsigned long nbr, char *base, int base_len,
		int count);
int	ft_ptptr(void *ptr, int count);

#endif