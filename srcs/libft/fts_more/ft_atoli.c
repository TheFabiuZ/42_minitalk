/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:59:50 by famirant          #+#    #+#             */
/*   Updated: 2022/12/07 18:06:51 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long int	ft_atoli(const char *nptr)
{
	int			i;
	int			is_negative;
	long int	number;

	number = 0;
	is_negative = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_negative++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (number * 10) + (nptr[i] - '0');
		i++;
	}
	if (is_negative % 2)
		number *= -1;
	return (number);
}
