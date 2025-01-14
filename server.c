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

/*	il kernel invoca mangesignal
	perchè l'ho associato al gestore
	di eventi sigaction.
*/
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
	/*all'interno della mia struttura
		sigaction denominata server_sigaction
		vado a definire il campo sa_sigaction,
		ovvero il miogestore di segnali. Utilizzo
		questo campo perchè questo gestore
		mi da maggiori informazioni. Quindi non uso
		il campo hendler della struc (come faccio in client).
		Al fine di usare questo gestore ho dovuto prima
		impostare il campo sa_flags a sa_siginfo. Infatti
		il solo modo che ho di usare sa_sigaction al oposto
		di sa_jandeler è impostare questa flag a Sa_siginfo.
		Ma ora grazie a questa flag posso accedere ad altre
		info come il pid del processo client*/
	server_sigaction.sa_sigaction = managesignal;
	sigaction(SIGUSR1, &server_sigaction, NULL);
	sigaction(SIGUSR2, &server_sigaction, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
