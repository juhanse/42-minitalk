/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:30:23 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/06 00:41:32 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_error(int type, int pid)
{
	if (type == 1)
		ft_printf("Usage: ./client [Server PID] [String to send]\n");
	else if (type == 2 && pid != -1)
		ft_printf("ERROR: Invalid PID: %d\n", pid);
	else if (type == 3 && pid != -1)
		ft_printf("ERROR: Failed to send signal to PID: %d\n", pid);
	exit(EXIT_FAILURE);
}

void	send_message(int pid, char *msg)
{
	int	i;
	int	letter;

	letter = 0;
	while (msg[letter])
	{
		i = -1;
		while (++i < 8)
		{
			if (((unsigned char)(msg[letter] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(msg[letter] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
		letter++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_error(1, -1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 99998)
		ft_error(2, pid);
	if (kill(pid, 0) < 0)
		ft_error(3, pid);
	send_message(pid, argv[2]);
	exit(EXIT_SUCCESS);
}
