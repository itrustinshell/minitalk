/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:40:45 by largenzi          #+#    #+#             */
/*   Updated: 2024/10/22 19:51:46 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_itoa(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);
void	printmsg(char *msg);
