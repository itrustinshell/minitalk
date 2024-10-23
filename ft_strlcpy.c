#include "minitalk.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	i;
	char	*initial;

	initial = (char *)src;
	src_length = ft_strlen(src);
	if (dstsize != 0)
	{
		i = dstsize - 1;
		while (*src != '\0' && i > 0)
		{
			*dst = *src;
			src++;
			dst++;
			i--;
		}
		*dst = '\0';
	}
	src = initial;
	return (src_length);
}
