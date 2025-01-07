/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/07 11:58:48 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_print_char(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_print_nb(int nb, int count)
{
	if (nb < 0)
	{
		count = ft_print_char('-', count);
		nb = -nb;
	}
	if (nb > 9)
	{
		count = ft_print_nb(nb / 10, count);
		count = ft_print_nb(nb % 10, count);
	}
	else
		count = ft_print_char(nb + 48, count);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	count;
	va_list args;

	i = -1;
	count = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1] == 'd')
		{
			i++;
			count = ft_print_nb(va_arg(args, int), count);
		}
		else
			count = ft_print_char(s[i], count);
	}
	va_end(args);
	return (count);
}
