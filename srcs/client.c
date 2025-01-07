/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:30:23 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/07 12:22:59 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send(int pid, char *msg)
{
	int	bit;
	int	letter;

	letter = 0;
	while (msg[letter])
	{
		bit = -1;
		while (++bit < 8)
		{
			if (((unsigned char)(msg[letter] >> (7 - bit)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(msg[letter] >> (7 - bit)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
		letter++;
	}
	bit = 0;
	while (bit++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
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
	if (kill(pid, 0) < 0)
	{
		ft_printf("ERROR: Failed to send signal to PID: %d\n", pid);
		return (0);
	}
	send(pid, argv[2]);
	return (0);
}
