/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:11:37 by largenzi          #+#    #+#             */
/*   Updated: 2024/10/22 20:10:19 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v' || *nptr == '\f'
		|| *nptr == '\r' || *nptr == ' ')
	{
		nptr++;
	}
	sign = 1;
	if (*nptr == '+')
	{
		nptr++;
	}
	else if (*nptr == '-')
	{
		nptr++;
		sign = -sign;
	}
	result = 0;
	while (ft_isdigit(*nptr) == 1)
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}
