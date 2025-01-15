/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/15 16:52:52 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_putchar(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putstr(char *s, int count)
{
	int	i;

	i = -1;
	while (s[++i])
		count = ft_putchar(s[i], count);
	return (count);
}

int	ft_putnbr(int nb, int count)
{
	if (nb < 0)
	{
		count = ft_putchar('-', count);
		nb = -nb;
	}
	if (nb > 9)
	{
		count = ft_putnbr(nb / 10, count);
		count = ft_putnbr(nb % 10, count);
	}
	else
		count = ft_putchar(nb + 48, count);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = -1;
	count = 0;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (s[i] == 's')
				count = ft_putstr(va_arg(args, char *), count);
			else if (s[i] == 'd')
				count = ft_putnbr(va_arg(args, int), count);
			else
				count = ft_putchar(s[i], count);
		}
		else
			count = ft_putchar(s[i], count);
	}
	va_end(args);
	return (count);
}
