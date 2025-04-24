/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:09:03 by famirant          #+#    #+#             */
/*   Updated: 2022/10/24 11:09:06 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_right_cs(t_print *table, int mode)
{
	int	n;

	n = table->wdt - table->len;
	if (!mode)
		while (n-- > 0)
			table->tl += ft_putchar_fd('0', 1);
	else
		while (n-- > 0)
			table->tl += ft_putchar_fd(' ', 1);
}

void	ft_left_cs(t_print *table, int mode)
{
	int	n;

	n = table->dwdt - table->len;
	if (table->wdt - table->len > 0)
		n -= table->wdt - table->len;
	if (!mode)
		while (n-- > 0)
			table->tl += ft_putchar_fd('0', 1);
	else
		while (n-- > 0)
			table->tl += ft_putchar_fd(' ', 1);
}
