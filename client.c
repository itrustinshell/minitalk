/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:39:25 by largenzi          #+#    #+#             */
/*   Updated: 2024/10/22 20:12:15 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_globalvariable = 0;

void	send_char(char c, int process_id)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_globalvariable = 0;
		if ((c >> i) & 1)
			kill(process_id, SIGUSR1);
		else
			kill(process_id, SIGUSR2);
		usleep(500);
		while (g_globalvariable == 0)
		{
			usleep(1000);
		}
		i--;
	}
}

void	server_acknoledge(int signal)
{
	(void)signal;
	g_globalvariable = 1;
}

int	main(int argc, char **argv)
{
	int					process_id;
	char				*s;
	int					i;
	int					*bitsarray;
	struct sigaction	client_sigaction;

	if (argc != 3)
		return (1);
	process_id = ft_atoi(argv[1]);
	s = argv[2];
	bitsarray = (int *)malloc(8 * sizeof(int));
	client_sigaction.sa_handler = server_acknoledge;
	sigemptyset(&client_sigaction.sa_mask);
	client_sigaction.sa_flags = 0;
	sigaction(SIGUSR1, &client_sigaction, NULL);
	i = 0;
	g_globalvariable = 1;
	while (s[i] != '\0')
	{
		send_char(s[i], process_id);
		i++;
	}
	send_char('\n', process_id);
	free(bitsarray);
	return (0);
}
