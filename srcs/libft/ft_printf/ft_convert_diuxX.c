/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_diuxX.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:09:49 by famirant          #+#    #+#             */
/*   Updated: 2022/10/24 12:09:50 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_numb2(t_print *table, char di, int numb, int negative)
{
	if (table->sp && !table->sign && !negative)
		table->tl += ft_putchar_fd(' ', 1);
	if (table->sign && numb >= 0 && !negative)
		table->tl += ft_putchar_fd('+', 1);
	ft_update_right(table, di, negative);
	if (table->pnt)
	{
		if (numb || table->prc)
			table->tl += ft_putnbr_nodash(numb);
	}
	else
		table->tl += ft_putnbr_nodash(numb);
	if (table->dwdt - table->len > 0 && table->dash)
		ft_left_cs(table, 1);
}

//if d || i
void	ft_print_numb(t_print *table, char di)
{
	int	numb;
	int	negative;

	negative = 0;
	numb = va_arg(table->args, int);
	if (numb < 0)
	{
		negative = 1;
		if (table->pnt || table->zero)
		{
			numb = (int)-numb;
			table->len = ft_unint_len(numb);
			table->dwdt--;
			table->wdt--;
		}
		else
			table->len = ft_unint_len((unsigned int)numb * -1) + 1;
	}
	else if (((numb && table->pnt && !table->prc) || table->prc) || !table->pnt)
		table->len = ft_unint_len((unsigned int)numb);
	ft_print_numb2(table, di, numb, negative);
}

//if u
void	ft_print_unsnumb(t_print *table)
{
	unsigned int	unumb;

	unumb = va_arg(table->args, unsigned int);
	table->len = ft_unint_len(unumb);
	ft_update_right(table, 'u', 0);
	if (((unumb && table->pnt && !table->prc) || table->prc) || !table->pnt)
		table->tl += ft_putunbr_fd(unumb, 1);
	else
		table->len = 0;
	if (!unumb && table->zero && !table->prc && table->pnt)
		table->tl += ft_putchar_fd(' ', 1);
	ft_update_left(table);
}

//if x || X
void	ft_print_hex_tab(t_print *table, char xX)
{
	unsigned int	hexn;

	hexn = va_arg(table->args, unsigned int);
	table->len = ft_hex_len(hexn);
	ft_update_right(table, xX, 0);
	if (table->is_zero && hexn && xX == 'x')
		table->tl += ft_putstr_fd("0x", 1);
	else if (table->is_zero && hexn && xX == 'X')
		table->tl += ft_putstr_fd("0X", 1);
	if (((hexn && table->pnt && !table->prc) || table->prc) || !table->pnt)
	{
		if (xX == 'x')
			table->tl += ft_print_hex((unsigned long long)hexn, 0);
		else
			table->tl += ft_print_hex_upper((unsigned long long)hexn, 0);
	}
	else
		table->len = 0;
	if (!hexn && table->zero && !table->prc && table->pnt)
		table->tl += ft_putchar_fd(' ', 1);
	ft_update_left(table);
}
