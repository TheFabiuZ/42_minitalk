/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengths_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:38:15 by famirant          #+#    #+#             */
/*   Updated: 2023/01/07 11:28:50 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_more.h"

// size_t	ft_arraylen(int array[])
// {
// 	//	// Using sizeof()
// 	// size_t	array_len;
// 	// size_t	array_element_len;
// 	//
// 	// array_len = sizeof(array);
// 	// array_element_len = sizeof(array[0]);
// 	// return (array_len / array_element_len);
//
// 	// // Using pointer arithmetic
// 	// return (*(&array + 1) - array);
// }
size_t	ft_arraylen(int *array)
{
	return (*(&array + 1) - array);
}
