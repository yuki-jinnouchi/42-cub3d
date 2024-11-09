/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:11:54 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/04 15:06:27 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	t_list	*pre_node;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	pre_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (!head)
			head = new_node;
		else
			pre_node->next = new_node;
		pre_node = new_node;
		lst = lst->next;
	}
	return (head);
}
