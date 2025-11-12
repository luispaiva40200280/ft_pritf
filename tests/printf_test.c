/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:37:04 by lpaiva            #+#    #+#             */
/*   Updated: 2025/11/12 21:59:47 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int				ret1;
	int				ret2;
	char			c;
	char			*str;
	int				num;
	unsigned int	u;
	void			*ptr;

	c = 'A';
	str = "Hello, World!";
	num = -12345;
	u = 4294967295;
	ptr = str;
	printf("\n===== ft_printf vs printf =====\n\n");
	// 1. Characters
	ret1 = ft_printf("My ft_printf: [%c]\n", c);
	ret2 = printf("Real printf:  [%c]\n", c);
	printf("Return values -> mine: %d | real: %d\n\n", ret1, ret2);
	// 2. Strings
	ret1 = ft_printf("My ft_printf: [%s]\n", str);
	ret2 = printf("Real printf:  [%s]\n", str);
	printf("Return values -> mine: %d | real: %d\n\n", ret1, ret2);
	// 3. Signed integers
	ret1 = ft_printf("My ft_printf: [%d] and [%i]\n", num, num);
	ret2 = printf("Real printf:  [%d] and [%i]\n", num, num);
	printf("Return values -> mine: %d | real: %d\n\n", ret1, ret2);
	// 4. Unsigned integers
	ret1 = ft_printf("My ft_printf: [%u]\n", u);
	ret2 = printf("Real printf:  [%u]\n", u);
	printf("Return values -> mine: %d | real: %d\n\n", ret1, ret2);
	// 5. Hexadecimal lowercase
	ret1 = ft_printf("My ft_printf: [%x]\n", 3735928559u);
	ret2 = printf("Real printf:  [%x]\n", 3735928559u);
	printf("Return values -> mine: %d | real: %d\n\n", ret1, ret2);
	// 6. Hexadecimal uppercase
	ret1 = ft_printf("My ft_printf: [%X]\n", 3735928559u);
	ret2 = printf("Real printf:  [%X]\n", 3735928559u);
	printf("Return values -> mine: %d | real: %d\n\n", ret1, ret2);
	// 7. Pointer
	ret1 = ft_printf("My ft_printf: [%p]\n", ptr);
	ret2 = printf("Real printf:  [%p]\n", ptr);
	printf("Return values -> mine: %d | real: %d\n\n", ret1, ret2);
	// 8. Percent sign
	ret1 = ft_printf("My ft_printf: [%%]\n");
	ret2 = printf("Real printf:  [%%]\n");
	printf("Return values -> mine: %d | real: %d\n\n", ret1, ret2);
	// 9. Mixed test
	ret1 = ft_printf("My ft_printf: Char=%c, Str=%s, Num=%d, Hex=%x, Ptr=%p\n",
			c, str, num, num, ptr);
	ret2 = printf("Real printf:  Char=%c, Str=%s, Num=%d, Hex=%x, Ptr=%p\n",
			c, str, num, num, ptr);
	printf("Return values -> mine: %d | real: %d\n\n", ret1, ret2);
	printf("==== Error force test ===== \n");
	ret1 = ft_printf("Hello %s! Number: %d\n", "porto", 42);
	printf("ft_printf returned: %d\n\n", ret1);
	
	return (0);
}
