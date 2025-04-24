/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_nodash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:57:31 by famirant          #+#    #+#             */
/*   Updated: 2022/10/22 10:57:34 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_putnbr_nodash(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putchar_fd('2', 1);
		n = 147483648;
	}
	if (n < 0)
		n *= -1;
	if (n > 9)
	{
		len += ft_putnbr_nodash(n / 10);
		len += ft_putnbr_nodash(n % 10);
	}
	else
	{
		len += ft_putchar_fd(n + 48, 1);
	}
	return (len);
}
