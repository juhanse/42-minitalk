/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:30:31 by juhanse           #+#    #+#             */
/*   Updated: 2024/12/04 16:03:38 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	signal_handler(int signum)
{
	static int	bits;
	static int	char_result;
	static int	len;
	static char	*result;

	if (!result)
		result = ft_strdup("");
	if (signum == SIGUSR1)
		char_result += 0;
	else if (signum == SIGUSR2)
		char_result += (1 * ft_recursive_power(2, 7 - bits));
	bits++;
	if (bits == 8)
	{
		result = letter_tosting(result, char_result);
		if (char_result == '\0')
		{
			printf("%s\n", result);
			result = NULL;
		}
		bits = 0;
		char_result = 0;
		len += 1;
	}
}

char	*letter_tosting(const char *s, const char letter)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char *)malloc((ft_strlen(s) + 2) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (s[i])
		tmp[j++] = s[i++];
	tmp[j++] = letter;
	tmp[j] = '\0';
	free ((void *)s);
	return (tmp);
}

int	main(void)
{
	struct sigaction	action;

	printf("%d", getpid());
	action.sa_handler = signal_handler;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
