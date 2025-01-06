/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:20:05 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/06 01:20:43 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_print_char(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

static int	ft_print_nb(int nb, int count)
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
			count = ft_print_nb(va_arg(args, int), count);
			i++;
		}
		else
			count = ft_print_char(s[i], count);
	}
	va_end(args);
	return (count);
}

static int	ft_overflow(long sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	tmp;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = result;
		result = (result * 10) + (str[i] - 48);
		if (tmp > result)
			return (ft_overflow(sign));
		i++;
	}
	return ((int) result * sign);
}
