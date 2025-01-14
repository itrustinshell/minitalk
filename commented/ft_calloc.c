#include "minitalk.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	len_memory;

	if (size != 0 && count > 2147483647 / size)
		return (0);
	len_memory = count * size;
	memory = (void *)malloc(len_memory);
	if (memory == NULL)
	{
		return (NULL);
	}
	else
		ft_memset(memory, '\0', len_memory);
	return (memory);
}
