/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:30:23 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/07 15:29:25 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_msg(int pid, char *s, size_t len)
{
	int		bit;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		bit = 0;
		while (bit < 7)
		{
			if ((s[i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit++;
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [Server PID] [String to send]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	send_msg(pid, argv[2], ft_strlen(argv[2]));
	return (0);
}
