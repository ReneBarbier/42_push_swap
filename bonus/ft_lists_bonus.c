/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:37:58 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/07 17:44:20 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

t_node	*ft_nodenew(int content)
{
	t_node	*nodo;

	nodo = malloc(sizeof(t_list));
	if (!nodo)
		return (NULL);
	nodo->content = content;
	nodo->next = NULL;
	return (nodo);
}

t_node	*ft_nodelast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_nodeadd_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!new)
		return ;
	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			tmp = ft_nodelast(*lst);
			tmp->next = new;
		}
	}
}

int	ft_nodesize(t_node *lst)
{
	int		count;

	count = 0;
	if (lst)
		count++;
	else
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_nodeadd_front(t_node **lst, t_node *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
