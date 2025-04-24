/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:27:18 by famirant          #+#    #+#             */
/*   Updated: 2022/12/21 16:32:21 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	long unsigned int	i;
	unsigned char		*str;

	str = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if ((unsigned char)c == str[i])
			return ((void *)&str[i]);
	return (0);
}
