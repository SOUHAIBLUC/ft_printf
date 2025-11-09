/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:09:14 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/08 18:54:07 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_print_p(unsigned long nb);
int		ft_print_s(char *str);
int		ft_print_diu(long nb);
int		ft_print_x1(unsigned int nb);
int		ft_print_x(unsigned int nb);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(char *s);
int		ft_putchar(char c);
#endif
