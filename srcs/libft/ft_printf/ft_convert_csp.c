/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_csp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:00:23 by famirant          #+#    #+#             */
/*   Updated: 2022/10/24 12:09:39 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//if c
void	ft_print_char(t_print *table)
{
	char	c;

	c = va_arg(table->args, int);
	table->len = 1;
	ft_update_right(table, 'c', 0);
	table->tl += write(1, &c, 1);
	ft_update_left(table);
}

//if s
void	ft_print_str(t_print *table)
{
	char	*str;

	str = va_arg(table->args, char *);
	if (!str)
		str = "(null)\0";
	table->len = ft_strlen(str);
	if (table->len > table->prc && table->pnt)
	{
		table->len = table->prc;
		if (!ft_strncmp(str, "(null)", 7))
			str = "";
	}
	ft_update_right(table, 's', 0);
	table->tl += ft_putnstr_fd(str, table->len, 1);
	ft_update_left(table);
}

//if p
void	ft_print_addr(t_print *table)
{
	unsigned long	addr;

	addr = va_arg(table->args, unsigned long);
	if (addr)
	{
		if (table->prc)
		{
			table->len = ft_ptr_len(addr);
			table->tl += ft_putstr_fd("0x", 1);
		}
		else
			table->len = ft_ptr_len(addr) + 2;
	}
	else
		table->len = 5;
	ft_update_right(table, 'p', 0);
	if (!addr)
		table->tl += ft_putstr_fd("(nil)\0", 1);
	else
	{
		if (!table->prc)
			table->tl += ft_putstr_fd("0x", 1);
		table->tl += ft_print_hex((unsigned long long)addr, 0);
	}
	ft_update_left(table);
}
