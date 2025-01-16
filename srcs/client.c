/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:30:23 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/16 16:13:36 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_message(int pid, char *s)
{
	int	i;
	int	bit;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
	{
		bit = -1;
		while (++bit < 8)
		{
			if ((s[i] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		printf("Usage: <PID> <message>");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 2)
	{
		printf("Invalid: <PID>");
		return (0);
	}
	send_message(pid, argv[2]);
	send_message(pid, "\n");
	return (0);
}
