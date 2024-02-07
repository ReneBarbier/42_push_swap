/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:47:40 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/11 12:41:16 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	diff_zero(int a, int b, int mode)
{
	static int	flipflop = 1;

	if (mode == 1)
	{
		if (a > b)
			return (a - b);
	}
	else
	{
		if (a > b)
			return (b);
		if (mode == 2)
			return (a);
		else
		{
			if (a == b)
			{
				if (flipflop++ % 2 == 0)
					return (a);
				else
					return (0);
			}
		}
	}
	return (0);
}

void	iter_search(t_vars *vr, t_moves *save_best, int iter_ind, int best_ind)
{
	t_node	*iterator;
	t_moves	save_iter;
	int		best_moves;
	int		iter_value;
	int		iter_moves;

	iterator = vr->a_stk;
	best_moves = INT_MAX;
	while (iterator)
	{
		iter_value = iterator->content;
		iter_moves = find_steps(vr, iter_ind, iter_value, &save_iter);
		if (iter_moves < best_moves)
		{
			best_moves = iter_moves;
			best_ind = iter_ind;
			*save_best = save_iter;
		}
		iterator = iterator->next;
		iter_ind++;
	}
}

void	push_cheapest(t_vars *vr, t_moves moves)
{
	while (--(moves.ra) != -1)
		ra(vr);
	while (--(moves.rb) != -1)
		rb(vr);
	while (--(moves.rs) != -1)
		rs(vr);
	while (--(moves.rra) != -1)
		rra(vr);
	while (--(moves.rrb) != -1)
		rrb(vr);
	while (--(moves.rrs) != -1)
		rrs(vr);
	pb(vr);
}

void	push_back(t_vars *vr)
{
	int		index;
	double	len;
	int		steps;
	int		j;

	while (vr->b_stk)
	{
		index = (double)find_position(vr->b_stk->content, vr, 0, -1);
		len = ft_nodesize(vr->a_stk);
		steps = index - (((len / 2) <= index) * (index - (len / 2)) * 2);
		j = 0;
		while (j++ < steps)
		{
			if (index <= len / 2)
				ra(vr);
			else
				rra(vr);
		}
		pa(vr);
	}
}

void	algorithm(t_vars *vr)
{
	t_moves	save_best;

	pb(vr);
	pb(vr);
	while (vr->a_stk->next->next->next)
	{
		iter_search(vr, &save_best, 0, 0);
		push_cheapest(vr, save_best);
	}
	biggest_to_top(vr, 0, 0);
	tree_case(vr);
	push_back(vr);
	lowest_to_top(vr, 0, 0);
}
