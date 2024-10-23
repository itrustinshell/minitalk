#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	printmsg(char *msg)
{
	int	len;

	len = ft_strlen(msg);
	write(1, msg, len);
}
