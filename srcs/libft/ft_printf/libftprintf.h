/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:24:49 by famirant          #+#    #+#             */
/*   Updated: 2022/12/22 15:29:31 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

// Libraries
# include "../fts_libft/libft.h"
# include <stdarg.h>

typedef struct s_print
{
	va_list	args;
	int		len;
	int		wdt;
	int		dwdt;
	int		prc;
	int		zero;
	int		pnt;
	int		dash;
	int		tl;
	int		sign;
	int		is_zero;
	int		perc;
	int		sp;
}	t_print;

// Functions
int		ft_printf(const char *format, ...);
t_print	*ft_initialise_tab(t_print *table);
char	*ft_exam_format(t_print *table, const char *format);
int		ft_char_in_array(char c, char *array);

// Prints
void	ft_print_char(t_print *table);
void	ft_print_str(t_print *table);
void	ft_print_addr(t_print *table);
void	ft_print_numb(t_print *table, char di);
void	ft_print_unsnumb(t_print *table);
void	ft_print_hex_tab(t_print *table, char xX);
void	ft_print_array(t_print *table);

// Print Hexadecimal
size_t	ft_print_hex(unsigned long long n, int err);
size_t	ft_print_hex_upper(unsigned long long n, int err);

// Put number without negative sign
size_t	ft_putnbr_nodash(int n);

// More Lengths
size_t	ft_ptr_len(unsigned long int n);
size_t	ft_unint_len(unsigned int n);
size_t	ft_hex_len(unsigned int n);

// Padding
void	ft_right_cs(t_print *table, int mode);
void	ft_left_cs(t_print *table, int mode);

// Update Table
void	ft_update_right(t_print *table, char type, int negative);
void	ft_update_right2(t_print *table, int negative, int tmp);
void	ft_update_right3(t_print *table, int negative);
void	ft_update_left(t_print *table);

#endif
