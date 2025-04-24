/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarray_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:48:01 by famirant          #+#    #+#             */
/*   Updated: 2023/01/07 13:07:53 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_more.h"
#include "../ft_printf/libftprintf.h"

size_t	ft_printarray_malloc_int(size_t array_len, int *array)
{
	size_t	printed_elements;

	printed_elements = 0;
	while (printed_elements < array_len)
	{
		ft_printf("%i", array[printed_elements]);
		++printed_elements;
		if (printed_elements != array_len)
			ft_printf(", ");
	}
	return (printed_elements);
}

size_t	ft_printarray_malloc_uint(size_t array_len, unsigned int *array)
{
	size_t	printed_elements;

	printed_elements = 0;
	while (printed_elements < array_len)
	{
		ft_printf("%u", array[printed_elements]);
		++printed_elements;
		if (printed_elements != array_len)
			ft_printf(", ");
	}
	return (printed_elements);
}
