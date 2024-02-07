/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:20:36 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/11 12:41:30 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	moves_tree_case(int x, t_vars *vr)
{
	if (x == 1)
		sa(vr);
	else if (x == 2)
		ra(vr);
	else if (x == 3)
	{
		ra(vr);
		sa(vr);
	}
	else if (x == 4)
		rra(vr);
	else if (x == 5)
	{
		rra(vr);
		sa(vr);
	}
}

void	tree_case(t_vars *vr)
{
	if (vr->a_stk->content > vr->a_stk->next->content)
	{
		if (vr->a_stk->next->content < vr->a_stk->next->next->content)
		{
			if (vr->a_stk->content < vr->a_stk->next->next->content)
				moves_tree_case(1, vr);
			else
				moves_tree_case(2, vr);
		}
		else
			moves_tree_case(3, vr);
	}
	else
	{
		if (vr->a_stk->next->content > vr->a_stk->next->next->content)
		{
			if (vr->a_stk->content > vr->a_stk->next->next->content)
				moves_tree_case(4, vr);
			else
				moves_tree_case(5, vr);
		}
		else
			return ;
	}
}

double	find_lowest(t_vars *vr, double len)
{
	t_node	*lower;
	t_node	*iter;
	int		i;

	i = 1;
	lower = vr->a_stk;
	lower->index = 0;
	iter = vr->a_stk->next;
	while (i++ < len)
	{
		if (iter->content < lower->content)
		{
			lower = iter;
			lower->index = i - 1;
		}
		iter = iter->next;
	}
	return (lower->index);
}

void	pop_lowest(t_vars *vr, double len)
{
	double	ind;
	int		steps;
	int		i;

	i = 1;
	len = ft_nodesize(vr->a_stk);
	ind = find_lowest(vr, len);
	steps = ind - (((len / 2) <= ind) * (ind - (len / 2)) * 2);
	i = 0;
	while (i++ < steps)
	{
		if (ind <= len / 2)
			ra(vr);
		else
			rra(vr);
	}
	pb(vr);
}

void	sort_stak(t_vars *vr)
{
	if (vr->n_num == 2)
		if (vr->a_stk->content > vr->a_stk->next->content)
			sa(vr);
	if (vr->n_num == 3)
		tree_case(vr);
	else if (vr->n_num == 4)
	{
		pop_lowest(vr, 4);
		tree_case(vr);
		pa(vr);
	}
	else if (vr->n_num == 5)
	{
		pop_lowest(vr, 0);
		pop_lowest(vr, 0);
		tree_case(vr);
		pa(vr);
		pa(vr);
	}
	else if (vr->n_num > 5)
		algorithm(vr);
}
