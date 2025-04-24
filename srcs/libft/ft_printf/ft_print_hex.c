/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:28:23 by famirant          #+#    #+#             */
/*   Updated: 2022/10/19 14:28:27 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_hex(unsigned long long n, int err)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (n < 16 && err == 1)
		len += ft_putchar_fd('0', 1);
	if (n >= 16)
	{
		len += ft_print_hex(n / 16, 0);
		len += ft_print_hex(n % 16, 0);
	}
	else
		len += ft_putchar_fd(base[n], 1);
	return (len);
}

size_t	ft_print_hex_upper(unsigned long long n, int err)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789ABCDEF";
	if (n < 16 && err == 1)
		len += ft_putchar_fd('0', 1);
	if (n >= 16)
	{
		len += ft_print_hex_upper(n / 16, 0);
		len += ft_print_hex_upper(n % 16, 0);
	}
	else
		len += ft_putchar_fd(base[n], 1);
	return (len);
}
