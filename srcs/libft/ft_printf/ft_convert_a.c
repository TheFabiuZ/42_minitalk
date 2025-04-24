/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:12:31 by famirant          #+#    #+#             */
/*   Updated: 2023/01/07 11:41:05 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// Print array of numbers (int *)
void	ft_print_array(t_print *table)
{
	int	*array;
	int	i;
	int	len;

	array = va_arg(table->args, int *);
	len = *(&array + 1) - array;
	i = -1;
	while (++i < len)
	{
		table->tl += ft_putnbr_fd(array[i], 1);
		if (i != len)
			table->tl += ft_putstr_fd(", ", 1);
	}
}

// // Print array of numbers (int *)
// void	ft_print_array(t_print *table)
// {
// 	int	*array;
// 	int	i;
// 	int	len;

// 	array = va_arg(table->args, int *);
// 	len = sizeof(array);
// 	i = -1;
// 	while (++i < len)
// 	{
// 		table->tl += ft_putnbr_fd(array[i], 1);
// 		if (i >= len)
// 			table->tl += ft_putstr_fd(", ", 1);
// 	}
// }