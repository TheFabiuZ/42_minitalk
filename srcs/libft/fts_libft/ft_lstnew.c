/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:39:45 by famirant          #+#    #+#             */
/*   Updated: 2022/10/10 17:39:46 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*llist;

	llist = malloc(sizeof(t_list));
	if (llist == NULL)
		return (0);
	llist->content = content;
	llist->next = NULL;
	return (llist);
}
