/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:08:03 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/13 14:41:33 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_check(va_list args, char format)
{
	int	c;

	if (format == 's')
		return (ft_print_s(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_diu(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_diu(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (ft_print_x1(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_print_x(va_arg(args, unsigned int)));
	else if (format == 'p')
		return (ft_print_p(va_arg(args, uintptr_t)));
	else if (format == 'c')
	{
		c = va_arg(args, int);
		return (write(1, &c, 1));
	}
	else if (format == '%')
		return (write(1, "%", 1));
	return (write(1, &format, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		nb;

	va_start(args, format);
	count = 0;
	i = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		nb = 0;
		if (format[i] == '%' && format[i + 1])
			nb = ft_check(args, format[++i]);
		else
			nb = write(1, &format[i], 1);
		if (nb == -1)
			return (-1);
		count += nb;
		i++;
	}
	va_end(args);
	return (count);
}
