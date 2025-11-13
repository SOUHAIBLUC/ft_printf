/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:13:24 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/13 11:14:27 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "ft_printf.h"

int main()
{
    int ret1, ret2;

    ret1 = printf("printf:    Hello %s!\n", "world");
    ret2 = ft_printf("ft_printf: Hello %s!\n", "world");
    printf("Return values -> printf: %d | ft_printf: %d\n\n", ret1, ret2);

}
