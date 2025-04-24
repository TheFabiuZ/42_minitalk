/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:48:24 by famirant          #+#    #+#             */
/*   Updated: 2022/12/21 16:28:34 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i[2];
	int				not_match;

	if (ft_strlen((char *)little) == 0)
		return ((char *)big);
	i[0] = 0;
	while (*big && i[0] < len && len + 1 - i[0] - ft_strlen((char *)little) > 0)
	{
		if (*big == *little)
		{
			i[1] = 0;
			not_match = 0;
			while (little[i[1]])
			{
				if (big[i[1]] != little[i[1]])
					not_match = 1;
				i[1]++;
			}
			if (not_match == 0)
				return ((char *)big);
		}
		big++;
		i[0]++;
	}
	return (0);
}
