/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:30:31 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/07 12:18:48 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	receive(int signum)
{
	static int				i = 0;
	static unsigned char	c = 0;

	if (signum == SIGUSR2)
		c = c << 1;
	else if (signum == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, receive);
		signal(SIGUSR2, receive);
	}
	return (0);
}
