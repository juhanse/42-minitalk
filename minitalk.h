/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:29:45 by juhanse           #+#    #+#             */
/*   Updated: 2024/12/04 14:39:43 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
int		ft_recursive_power(int nb, int power);

void	send_message(int pid, char *message);

void	signal_handler(int signum);

#endif
