/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:13:40 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/08 18:49:21 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_fill(unsigned int nb, char *buffer)
{
	int (i), (len), (rem);
	i = 0;
	len = 0;
	while (nb > 0)
	{
		rem = nb % 16;
		if (rem < 10)
			buffer[i] = '0' + rem;
		else
			buffer[i] = 'a' + (rem - 10);
		nb /= 16;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

int	ft_print_x(unsigned int nb)
{
	char	*str;
	char	rest[20];
	int		i;
	int		len;

	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	str = ft_fill(nb, rest);
	len = ft_strlen(str);
	i = len;
	while (i-- > 0)
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
	}
	return (len);
}
