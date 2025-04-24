/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:26:39 by famirant          #+#    #+#             */
/*   Updated: 2022/10/03 14:26:42 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	is_negative;
	int	number;

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
