/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:29:45 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/06 00:27:15 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
int		ft_recursive_power(int nb, int power);

void	send_message(int pid, char *message);

char	*letter_tosting(const char *s, const char letter);
void	signal_handler(int signum);

#endif
