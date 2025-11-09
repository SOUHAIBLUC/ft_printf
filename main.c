/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:44:52 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/08 18:57:27 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char			c;
	char			*str;
	int				num;
	unsigned int	unum;
	void			*ptr;

	int ret1, ret2;
	c = 'A';
	str = "Hello, World!";
	num = -42;
	unum = 4294967295U;
	ptr = str;
	printf("===== BASIC TESTS =====\n");
	ret1 = printf("printf: %c %s %d %i %u %x %X %p %%\n", c, str, num, num,
			unum, unum, unum, ptr);
	ret2 = ft_printf("ft_printf: %c %s %d %i %u %x %X %p %%\n", c, str, num,
			num, unum, unum, unum, ptr);
	printf("\nReturn values: printf=%d | ft_printf=%d\n", ret1, ret2);
	printf("\n===== EDGE CASES =====\n");
	ft_printf("NULL string: %s\n", (char *)NULL);
	ft_printf("Zero pointer: %p\n", (void *)0);
	ft_printf("Zero number (hex): %x %X\n", 0, 0);
	ft_printf("Large number: %u %x %X\n", 4294967295U, 4294967295U,
			4294967295U);
	ft_printf("Negative number: %d %i\n", -2147483648, -1);
	ft_printf("Character test: %c %c %c\n", 'A', 0, 'Z');
	ft_printf("Mixed test: %s %d %p %x %%\n", "Mix", 12345, &num, 255);
	printf("\n===== RETURN VALUE TESTS =====\n");
	ret1 = ft_printf("This should print 21 chars\n");
	printf(" => Return value: %d\n", ret1);
	return (0);
}
