/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:40:39 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/30 10:40:54 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rb(t_vars *vr)
{
	t_node	**stak;
	t_node	*tmp;

	stak = &(vr->b_stk);
	tmp = (*stak);
	(*stak) = (*stak)->next;
	tmp->next = NULL;
	ft_nodeadd_back(stak, tmp);
	ft_printf("rb\n");
}

void	rs(t_vars *vr)
{
	t_node	**stak;
	t_node	*tmp;

	stak = &(vr->b_stk);
	tmp = (*stak);
	(*stak) = (*stak)->next;
	tmp->next = NULL;
	ft_nodeadd_back(stak, tmp);
	stak = &(vr->a_stk);
	tmp = (*stak);
	(*stak) = (*stak)->next;
	tmp->next = NULL;
	ft_nodeadd_back(stak, tmp);
	ft_printf("rr\n");
}

void	rra(t_vars *vr)
{
	t_node	**stak;
	t_node	*tmp;

	stak = &(vr->a_stk);
	tmp = (*stak);
	while (tmp->next->next)
		tmp = tmp->next;
	ft_nodeadd_front(stak, tmp->next);
	tmp->next = NULL;
	ft_printf("rra\n");
}

void	rrb(t_vars *vr)
{
	t_node	**stak;
	t_node	*tmp;

	stak = &(vr->b_stk);
	tmp = (*stak);
	while (tmp->next->next)
		tmp = tmp->next;
	ft_nodeadd_front(stak, tmp->next);
	tmp->next = NULL;
	ft_printf("rrb\n");
}

void	rrs(t_vars *vr)
{
	t_node	**stak;
	t_node	*tmp;

	stak = &(vr->b_stk);
	tmp = (*stak);
	while (tmp->next->next)
		tmp = tmp->next;
	ft_nodeadd_front(stak, tmp->next);
	tmp->next = NULL;
	stak = &(vr->a_stk);
	tmp = (*stak);
	while (tmp->next->next)
		tmp = tmp->next;
	ft_nodeadd_front(stak, tmp->next);
	tmp->next = NULL;
	ft_printf("rrr\n");
}
