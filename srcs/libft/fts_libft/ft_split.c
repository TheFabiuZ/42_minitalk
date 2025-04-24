/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:37:31 by famirant          #+#    #+#             */
/*   Updated: 2022/12/21 16:27:50 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	on_off;

	i = 0;
	on_off = 0;
	while (*str)
	{
		if (*str != c && on_off == 0)
		{
			on_off = 1;
			i++;
		}
		else if (*str == c)
			on_off = 0;
		str++;
	}
	return (i);
}

static char	*ft_strdup2(const char *s, int start, int finish)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**strs;
	int				i;
	int				j;
	int				index;

	strs = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !strs)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= (int)ft_strlen((char *)s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && index >= 0)
		{
			strs[j++] = ft_strdup2(s, index, i);
			index = -1;
		}
		i++;
	}
	strs[j] = 0;
	return (strs);
}
