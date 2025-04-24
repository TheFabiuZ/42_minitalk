/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:04:31 by famirant          #+#    #+#             */
/*   Updated: 2022/10/18 10:04:42 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_in_array(char c, char *array)
{
	while (*array)
	{
		if (c == *array)
			return (1);
		array++;
	}
	return (0);
}
