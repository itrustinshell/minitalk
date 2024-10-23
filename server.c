/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:44:34 by largenzi          #+#    #+#             */
/*   Updated: 2024/10/22 20:10:04 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_buffer_to_char(int *buffer_char)
{
	int		i;
	int		j;
	int		num;
	char	c;

	num = 0;
	i = 7;
	j = 0;
	while (i >= 0)
	{
		if (buffer_char[i] == 1)
			num = num + (1 << j);
		i--;
		j++;
	}
	c = (char)num;
	write(1, &c, 1);
}

void	managesignal(int sig, siginfo_t *info, void *other)
{
	int			buffer_char[8];
	static int	i;
	pid_t		client_pid;

	(void)other;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
	{
		buffer_char[i] = 1;
		kill(client_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		buffer_char[i] = 0;
		kill(client_pid, SIGUSR1);
	}
	i++;
	if (i == 8)
	{
		i = 0;
		convert_buffer_to_char(buffer_char);
	}
}

int	main(void)
{
	struct sigaction	server_sigaction;
	pid_t				pid;
	char				*converted_pid;

	pid = getpid();
	converted_pid = ft_itoa(pid);
	printmsg(converted_pid);
	write(1, "\n", 1);
	server_sigaction.sa_flags = SA_SIGINFO;
	sigemptyset(&server_sigaction.sa_mask);
	server_sigaction.sa_sigaction = managesignal;
	sigaction(SIGUSR1, &server_sigaction, NULL);
	sigaction(SIGUSR2, &server_sigaction, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
