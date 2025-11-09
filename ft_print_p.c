/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:09:25 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/08 18:53:27 by so-ait-l         ###   ########.fr       */
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

int	ft_print_p(unsigned long nb)
{
	char	*str;
	char	rest[20];

	int (i), (len), (count), (ret);
	count = 0;
	write(1, "0x", 2);
	count = 2;
	if (nb == 0)
	{
		ft_putchar('0');
		return (3);
	}
	str = ft_fill(nb, rest);
	len = ft_strlen(str);
	i = len - 1;
	while (i >= 0)
	{
		ret = write(1, &str[i], 1);
		if (ret == -1)
			return (-1);
		count++;
		i--;
	}
	return (count);
}
