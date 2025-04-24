/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:11:05 by famirant          #+#    #+#             */
/*   Updated: 2022/12/21 16:29:13 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	slen;
	unsigned int	dlen;

	slen = ft_strlen((char *)src);
	dlen = ft_strlen((char *)dst);
	j = dlen;
	if (size == 0 || size <= dlen)
		return (slen + size);
	i = 0;
	while (i < size - dlen - 1 && src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (slen + dlen);
}
