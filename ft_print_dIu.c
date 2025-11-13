/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dIu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:58:23 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/12 09:59:14 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static int	ft_count(long n)
{
	int	count;

	if (n == 0)
		count = 1;
	else
		count = 0;
	if (n < 0)
		count += 1;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa(long n)
{
	char	*ptr;
	long	nb;

	int (last_index), (len), (i);
	len = ft_count(n);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	nb = n;
	last_index = -1;
	if (n < 0)
	{
		nb = -n;
		last_index = 0;
		ptr[0] = '-';
	}
	i = len - 1;
	while (i != last_index)
	{
		ptr[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	ptr[len] = '\0';
	return (ptr);
}

int	ft_print_diu(long nb)
{
	int		len;
	int		ret;
	char	*str;

	str = ft_itoa(nb);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	ret = write(1, str, len);
	free(str);
	if (ret == -1)
		return (-1);
	return (len);
}
