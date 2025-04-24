/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:47:41 by famirant          #+#    #+#             */
/*   Updated: 2022/10/04 11:47:42 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = -1;
	while (*(s + ++i))
		if (ch == s[i])
			return ((char *)&s[i]);
	if (ch == '\0' && s[i] == ch)
		return ((char *)&s[i]);
	return (0);
}
