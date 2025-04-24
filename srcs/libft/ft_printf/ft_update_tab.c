/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:52:25 by famirant          #+#    #+#             */
/*   Updated: 2022/10/24 11:52:26 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_update_right3(t_print *table, int negative)
{
	if (table->wdt && !table->dash)
	{
		ft_right_cs(table, 1);
		if (negative)
			table->tl += ft_putchar_fd('-', 1);
	}
	else if (negative)
		table->tl += ft_putchar_fd('-', 1);
}

void	ft_update_right2(t_print *table, int negative, int tmp)
{
	if (table->zero && !table->dash && table->wdt && !table->pnt)
	{
		if (negative)
			table->tl += ft_putchar_fd('-', 1);
		ft_right_cs(table, 0);
	}
	else if (table->prc && table->wdt <= table->prc)
	{
		table->wdt = table->prc;
		if (negative)
			table->tl += ft_putchar_fd('-', 1);
		ft_right_cs(table, 0);
	}
	else if (table->wdt > table->prc && table->zero && table->prc > table->len)
	{
		tmp = table->wdt;
		table->wdt -= table->prc - table->len;
		ft_right_cs(table, 1);
		if (negative)
			table->tl += ft_putchar_fd('-', 1);
		table->wdt = tmp - table->wdt + table->len;
		ft_right_cs(table, 0);
	}
	else
		ft_update_right3(table, negative);
}

void	ft_update_right(t_print *table, char type, int negative)
{
	int	tmp;

	tmp = 0;
	if (ft_char_in_array(type, "csp"))
		if (table->wdt && !table->dash)
			ft_right_cs(table, 1);
	if (ft_char_in_array(type, "diuxX"))
		ft_update_right2(table, negative, tmp);
	if (type == 'p' && table->prc)
	{
		table->wdt = table->prc;
		ft_right_cs(table, 0);
	}
}

void	ft_update_left(t_print *table)
{
	if (table->dwdt && table->dash)
		ft_left_cs(table, 1);
}
