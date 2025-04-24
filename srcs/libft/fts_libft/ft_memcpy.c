/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:34:16 by famirant          #+#    #+#             */
/*   Updated: 2022/12/21 16:31:32 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	const char		*prov_src;
	char			*prov_dest;

	prov_src = src;
	prov_dest = dest;
	i = 0;
	while (i < n)
	{
		*(prov_dest + i) = *(prov_src + i);
		i++;
	}
	return (dest);
}
