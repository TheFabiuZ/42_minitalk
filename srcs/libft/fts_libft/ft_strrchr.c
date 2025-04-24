/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:47:57 by famirant          #+#    #+#             */
/*   Updated: 2022/10/04 11:47:58 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				len;
	unsigned char	ch;

	if (ft_strchr(s, c) == NULL)
		return (0);
	ch = (unsigned char)c;
	len = 0;
	while (s[len])
		len++;
	if (ch == '\0')
		return ((char *)&s[len]);
	i = len;
	while (*(s + --i) && i >= 0)
		if (ch == s[i])
			return ((char *)&s[i]);
	return (0);
}
