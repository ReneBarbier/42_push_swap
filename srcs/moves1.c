/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:34:28 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/30 10:41:11 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_vars *vr)
{
	t_node	**stak;
	t_node	*tmp;

	stak = &vr->a_stk;
	tmp = (*stak);
	(*stak) = (*stak)->next;
	tmp->next = (*stak)->next;
	(*stak)->next = tmp;
	ft_printf("sa\n");
}

void	sb(t_vars *vr)
{
	t_node	**stak;
	t_node	*tmp;

	stak = &vr->b_stk;
	tmp = (*stak);
	(*stak) = (*stak)->next;
	tmp->next = (*stak)->next;
	(*stak)->next = tmp;
	ft_printf("sb\n");
}

void	pa(t_vars *vr)
{
	t_node	**from;
	t_node	**to;
	t_node	*tmp;

	from = &(vr->b_stk);
	to = &(vr->a_stk);
	tmp = (*from);
	(*from) = (*from)->next;
	tmp->next = NULL;
	ft_nodeadd_front(to, tmp);
	ft_printf("pa\n");
}

void	pb(t_vars *vr)
{
	t_node	**from;
	t_node	**to;
	t_node	*tmp;

	from = &(vr->a_stk);
	to = &(vr->b_stk);
	tmp = (*from);
	(*from) = (*from)->next;
	tmp->next = NULL;
	ft_nodeadd_front(to, tmp);
	ft_printf("pb\n");
}

void	ra(t_vars *vr)
{
	t_node	**stak;
	t_node	*tmp;

	stak = &(vr->a_stk);
	tmp = (*stak);
	(*stak) = (*stak)->next;
	tmp->next = NULL;
	ft_nodeadd_back(stak, tmp);
	ft_printf("ra\n");
}
