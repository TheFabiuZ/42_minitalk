/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:10:18 by famirant          #+#    #+#             */
/*   Updated: 2023/02/27 10:55:21 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_more.h"

int	ft_usleep(int time_i)
{
	while (--time_i >= 0)
		;
	return (-1);
}
