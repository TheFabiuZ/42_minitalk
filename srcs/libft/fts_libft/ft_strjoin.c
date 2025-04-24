/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:37:09 by famirant          #+#    #+#             */
/*   Updated: 2022/12/21 16:29:19 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	int		i;
	int		j;

	nstr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (nstr != NULL)
	{
		i = 0;
		while (s1[i])
		{
			nstr[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			nstr[i] = s2[j];
			j++;
			i++;
		}
		nstr[i] = '\0';
		return (nstr);
	}
	return (0);
}
