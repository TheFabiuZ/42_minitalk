/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:40:46 by famirant          #+#    #+#             */
/*   Updated: 2022/10/10 17:40:48 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsclear(t_list *lst, t_list *new_lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	ft_lstclear(&new_lst, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!lst || !f || !del)
		return (0);
	new_elem = ft_lstnew(f(lst->content));
	if (!new_elem)
	{
		ft_lstclear(&lst, del);
		return (0);
	}
	new_lst = new_elem;
	lst = lst->next;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstsclear(lst, new_lst, del);
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
