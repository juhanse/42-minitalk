/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:30:31 by juhanse           #+#    #+#             */
/*   Updated: 2026/03/20 00:18:38 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static char		current = 0;
	static pid_t	client_pid = 0;

	(void)context;
	if (info->si_pid != 0 && info->si_pid != client_pid)
	{
		bit = 0;
		current = 0;
		client_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		current |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &current, 1);
		if (current == '\0')
			write(1, "\n", 1);
		bit = 0;
		current = 0;
	}
	if (client_pid != 0)
		kill(client_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Invalid arguments\n");
		return (0);
	}
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", getpid());
	ft_printf("Waiting for a message...\n");
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
