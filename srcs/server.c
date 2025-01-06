/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:30:31 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/06 01:35:17 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	sigint_handler(int sig_num)
{
	(void)sig_num;
	ft_printf("Received SIGINT signal, exiting...\n");
	exit(EXIT_SUCCESS);
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	int			client_pid;
	static int	bit_count = 0;
	static char	current_char = 0;

	(void)context;
	client_pid = info->si_pid;
	if (signum == SIGUSR1)
		current_char |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Server PID: %d\n", getpid());
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handle_signal;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	signal(SIGINT, sigint_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
