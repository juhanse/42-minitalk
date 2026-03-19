/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:30:23 by juhanse           #+#    #+#             */
/*   Updated: 2026/03/19 15:57:38 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_server_ready = 0;

void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_server_ready = 1;
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		g_server_ready = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_server_ready == 0)
			usleep(50);
	}
}

void	send_message(int pid, char *s)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		send_char(pid, s[i]);
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <message>\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 2)
	{
		ft_printf("Invalid: <PID>\n");
		return (0);
	}
	signal(SIGUSR1, ack_handler);
	send_message(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
