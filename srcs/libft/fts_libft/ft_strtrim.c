/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:37:21 by famirant          #+#    #+#             */
/*   Updated: 2022/12/21 16:28:26 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strtrim2(char const *s1, char const *set, int len)
{
	int		i;
	int		trim;

	i = 0;
	while (set[i])
	{
		trim = 0;
		if (set[i] == s1[0])
		{
			len--;
			s1++;
			trim++;
		}
		if (set[i] == s1[len - 1])
		{
			len--;
			trim++;
		}
		if (!trim)
			i++;
		else if (i > 0)
			i = 0;
	}
	return (len);
}

char const	*ft_strtrim3(char const *s1, char const *set, int len)
{
	int		i;
	int		trim;

	i = 0;
	while (set[i])
	{
		trim = 0;
		if (set[i] == s1[0])
		{
			len--;
			s1++;
			trim++;
		}
		if (set[i] == s1[len - 1])
		{
			len--;
			trim++;
		}
		if (!trim)
			i++;
		else if (i > 0)
			i = 0;
	}
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	int		len;

	len = ft_strlen((char *)s1);
	len = ft_strtrim2(s1, set, len);
	s1 = ft_strtrim3(s1, set, len);
	if (len <= 0)
		len = 0;
	strim = malloc(len + 1);
	if (strim != NULL)
	{
		ft_strlcpy(strim, s1, len + 1);
		strim[len] = '\0';
		return (strim);
	}
	return (0);
}
