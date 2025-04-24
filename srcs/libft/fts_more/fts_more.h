/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_more.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:24:03 by famirant          #+#    #+#             */
/*   Updated: 2023/02/02 09:15:29 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTS_MORE_H

# define FTS_MORE_H

# include "../fts_libft/libft.h"
# include <stdarg.h>

// Functions
/*Convert ASCII to long integer*/
long int	ft_atoli(const char *nptr);
/*See if the character(c) is in array*/
int			ft_char_in_array(char c, char *array);

// ft_lengths/ft_lengths_2
/*Number length*/
size_t		ft_numblen(int n);
/*Pointer length*/
size_t		ft_ptrlen(unsigned long int n);
/*Unsigned Integer length*/
size_t		ft_unintlen(unsigned int n);
/*Hexdecimal length*/
size_t		ft_hexlen(unsigned int n);
/*Array length of fixed size (array[])*/
size_t		ft_arraylen(int *array);

// ft_new_array
/* WORK IN PROGRESS
	Create a new array of integers
*/
int			*ft_new_array_atoi(char *s);

// ft_printarray_malloc
/*Print integers of array with the len of the array*/
size_t		ft_printarray_malloc_int(size_t array_len, int *array);
/*Print unsigned integers of array with the len of the array*/
size_t		ft_printarray_malloc_uint(size_t array_len, unsigned int *array);

// ft_calloc
/*Create a memory of n bytes[count] * sizeof(type)[size]*/
void		*ft_calloc(size_t count, size_t size);
/*
  Create a memory of n bytes[count] * sizeof(type)[size].
  If fail to alloc memory, the program EXIT with EXIT_FAILURE
*/
void		*ft_calloc_exit(size_t count, size_t size);

// ft_power
/*
  int	ft_recursive_power(int nb, int power)
  This function returns the result of nb ^ power
  Example: ft_recursive_power(2, 3) = 2 ^ 3 = 8
*/
int			ft_recursive_power(int nb, int power);

// ft_sleep
/*
  Sleep for unit seconds (time_i)
  This function returns -1 on exit
*/
int			ft_usleep(int time_i);

#endif
