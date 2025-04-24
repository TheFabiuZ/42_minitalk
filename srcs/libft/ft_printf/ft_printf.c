/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:24:30 by famirant          #+#    #+#             */
/*   Updated: 2022/10/12 12:24:32 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_print	*ft_initialise_tab(t_print *table)
{
	table->len = 0;
	table->wdt = 0;
	table->dwdt = 0;
	table->prc = 0;
	table->zero = 0;
	table->pnt = 0;
	table->sign = 0;
	table->tl = 0;
	table->is_zero = 0;
	table->dash = 0;
	table->perc = 0;
	table->sp = 0;
	return (table);
}

int	ft_printf(const char *format, ...)
{
	int		retval;
	t_print	*table;

	table = (t_print *)malloc(sizeof(t_print));
	if (!table || !format)
		return (-1);
	ft_initialise_tab(table);
	va_start(table->args, format);
	retval = 0;
	while (*format)
	{
		if (*format != '%')
			retval += write(1, format, 1);
		else
		{
			format = ft_exam_format(table, format + 1);
			retval += table->tl;
			ft_initialise_tab(table);
		}
		format++;
	}
	va_end(table->args);
	free(table);
	return (retval);
}
