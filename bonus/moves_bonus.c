/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:35:16 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/07 16:41:16 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	s(t_node **stak)
{
	t_node	*tmp;

	if (*stak)
	{
		if ((*stak)->next)
		{
			tmp = (*stak);
			(*stak) = (*stak)->next;
			tmp->next = (*stak)->next;
			(*stak)->next = tmp;
		}
	}
}

void	ss(t_node **stak_a, t_node **stak_b)
{
	s(stak_a);
	s(stak_b);
}

void	p(t_node **from, t_node **to)
{
	t_node	*tmp;

	if (*from)
	{
		tmp = (*from);
		(*from) = (*from)->next;
		tmp->next = NULL;
		ft_nodeadd_front(to, tmp);
	}
}

void	r(t_node **stak)
{
	t_node	*tmp;

	if (*stak)
	{
		if ((*stak)->next)
		{
			tmp = (*stak);
			(*stak) = (*stak)->next;
			tmp->next = NULL;
			ft_nodeadd_back(stak, tmp);
		}
	}
}

void	rrx(t_node **stak)
{
	t_node	*tmp;

	if (*stak)
	{
		if ((*stak)->next)
		{
			tmp = (*stak);
			while (tmp->next->next)
				tmp = tmp->next;
			ft_nodeadd_front(stak, tmp->next);
			tmp->next = NULL;
		}
	}
}
