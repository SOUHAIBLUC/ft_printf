/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:09:25 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/13 15:01:18 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_fill(uintptr_t nb, char *buffer)
{
	int(i), (len), (rem);
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

int	ft_print_p(uintptr_t nb)
{
	char	*str;
	char	rest[20];

	int(i), (len), (count), (ret);
	count = 0;
	if (nb == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
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
