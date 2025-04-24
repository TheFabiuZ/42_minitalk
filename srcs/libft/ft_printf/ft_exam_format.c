/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exam_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:29:22 by famirant          #+#    #+#             */
/*   Updated: 2022/12/22 15:21:16 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_isflag_b2(t_print *table, const char *format)
{
	if (*format == ' ')
	{
		table->sp = 1;
		format++;
	}
	if (*format == '+')
	{
		table->sign = 1;
		format++;
	}
	if (*format == '.')
	{
		table->pnt = 1;
		format++;
		if (*format == '0')
			format++;
	}
	return (format);
}

const char	*ft_isflag_b1(t_print *table, const char *format)
{
	if (*format == '#')
	{
		table->is_zero = 1;
		format++;
	}
	if (*format == '0')
	{
		table->zero = 1;
		format++;
	}
	if (*format == '-')
	{
		table->dash = 1;
		format++;
	}
	return (ft_isflag_b2(table, format));
}

const char	*ft_isconversion(t_print *table, const char *format)
{
	if (*format == 'c')
		ft_print_char(table);
	if (*format == 's')
		ft_print_str(table);
	if (*format == 'p')
		ft_print_addr(table);
	if (*format == 'd' || *format == 'i')
		ft_print_numb(table, *format);
	if (*format == 'u')
		ft_print_unsnumb(table);
	if (*format == 'x' || *format == 'X')
		ft_print_hex_tab(table, *format);
	if (*format == '%')
		table->tl += write(1, "%", 1);
	if (*format == 'a')
		ft_print_array(table);
	return (format);
}

char	*ft_exam_format(t_print *table, const char *format)
{
	while (!ft_char_in_array(*format, "cspdiuxX%a"))
	{
		format = ft_isflag_b1(table, format);
		if (!ft_char_in_array(*format, "#0- +."))
		{
			if (ft_isdigit(*format))
			{
				if (*(format - 1) == '-')
					table->dwdt = ft_atoi(format);
				else if (*(format - 1) == '.')
					table->prc = ft_atoi(format);
				else
					table->wdt = ft_atoi(format);
				while (ft_isdigit(*format))
					format++;
			}
			else
				break ;
		}
	}
	return ((char *)ft_isconversion(table, format));
}
