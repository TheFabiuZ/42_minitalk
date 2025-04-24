/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:38:30 by famirant          #+#    #+#             */
/*   Updated: 2022/10/07 16:38:31 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
		i++;
	}
	return (i);
}

size_t	ft_putnstr_fd(char *s, int n, int fd)
{
	int	i;

	i = 0;
	while (*s && n)
	{
		ft_putchar_fd(*s, fd);
		s++;
		i++;
		n--;
	}
	return (i);
}
