/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:40:17 by largenzi          #+#    #+#             */
/*   Updated: 2024/10/22 19:41:22 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*special_cases(int n)
{
	char	*output;
	char	*min;

	output = NULL;
	if (n == 0)
	{
		output = (char *)malloc(2 * sizeof(char));
		if (output == NULL)
			return (NULL);
		output[0] = '0';
		output[1] = '\0';
		return (output);
	}
	if (n == -2147483648)
	{
		min = "-2147483648";
		output = (char *)malloc(ft_strlen(min) + 1);
		if (output == NULL)
			return (NULL);
		ft_strlcpy(output, min, 12);
		return (output);
	}
	return (output);
}

static char	*build_output(int divisor, int number, char *output, int n)
{
	int		converted_number;

	converted_number = 0;
	while (divisor > 1)
	{
		converted_number = ((number / divisor) % 10) + '0';
		divisor = divisor / 10;
		output[n] = converted_number;
		n++;
	}
	converted_number = ((number / divisor) % 10) + '0';
	output[n] = converted_number;
	return (output);
}

static char	*final(int how_many_digits, int divisor, int number, char sign)
{
	int		n;
	char	*output;

	output = NULL;
	n = 0;
	if (sign == '-')
	{
		output = ft_calloc((how_many_digits + 1 + 1), sizeof(char));
		if (output == NULL)
			return (NULL);
		output[n] = sign;
		n++;
		output = build_output(divisor, number, output, n);
	}
	else if (sign == '\0')
	{
		output = ft_calloc((how_many_digits + 1), sizeof(char));
		if (output == NULL)
			return (NULL);
		output = build_output(divisor, number, output, n);
	}
	return (output);
}

static char	*second_part(char sign, int number, int n)
{
	char	*output;
	size_t	how_many_digits;
	int		divisor;

	how_many_digits = 1;
	divisor = 1;
	while (number >= 10)
	{
		how_many_digits++;
		number = number / 10;
		divisor = divisor * 10;
	}
	number = n;
	output = final(how_many_digits, divisor, number, sign);
	return (output);
}

char	*ft_itoa(int n)
{
	char	sign;
	char	*output;
	int		number;

	if (n == 0 || n == -2147483648)
	{
		output = special_cases(n);
		return (output);
	}
	sign = '\0';
	if (n < 0)
	{
		sign = '-';
		n = -n;
	}
	number = n;
	output = second_part(sign, number, n);
	return (output);
}
