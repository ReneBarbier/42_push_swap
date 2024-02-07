/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:19:12 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/30 13:40:37 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_under(int value, t_vars *vr, int low_index, int i)
{
	t_node	*iterator;
	int		high_index;
	int		high_value;
	int		low_value;

	low_value = INT_MIN;
	high_value = value;
	iterator = vr->b_stk;
	while (iterator)
	{
		if (iterator->content < value && iterator->content > low_value)
		{
			low_value = iterator->content;
			low_index = i;
		}
		if (iterator->content > high_value)
			high_index = i;
		if (iterator->content > high_value)
			high_value = iterator->content;
		iterator = iterator->next;
		i++;
	}
	if (low_index == -1)
		return (high_index);
	return (low_index);
}

void	save_moves(t_scores a, t_scores b, int mode, t_moves *save_iter)
{
	save_iter->ra = 0;
	save_iter->rb = 0;
	save_iter->rra = 0;
	save_iter->rrb = 0;
	save_iter->rrs = 0;
	save_iter->rs = 0;
	if (mode == 0)
	{
		save_iter->rs = diff_zero(a.r_mvs, b.r_mvs, 2);
		save_iter->ra = diff_zero(a.r_mvs, b.r_mvs, 1);
		save_iter->rb = diff_zero(b.r_mvs, a.r_mvs, 1);
	}
	else if (mode == 1)
	{
		save_iter->rrs = diff_zero(a.rr_mvs, b.rr_mvs, 2);
		save_iter->rra = diff_zero(a.rr_mvs, b.rr_mvs, 1);
		save_iter->rrb = diff_zero(b.rr_mvs, a.rr_mvs, 1);
	}
	else
	{
		save_iter->ra = diff_zero(a.rr_mvs, a.r_mvs, 3);
		save_iter->rra = diff_zero(a.r_mvs, a.rr_mvs, 3);
		save_iter->rb = diff_zero(b.rr_mvs, b.r_mvs, 3);
		save_iter->rrb = diff_zero(b.r_mvs, b.rr_mvs, 3);
	}
}

int	best_comb_rotations(t_scores a, t_scores b, t_moves *save_iter)
{
	int	r_cmb;
	int	rr_cmb;
	int	ind;
	int	a_low;
	int	b_low;

	r_cmb = (a.r_mvs > b.r_mvs) * a.r_mvs + (a.r_mvs <= b.r_mvs) * b.r_mvs;
	rr_cmb = (a.rr_mvs > b.rr_mvs) \
	* a.rr_mvs + (a.rr_mvs <= b.rr_mvs) * b.rr_mvs;
	a_low = (a.r_mvs > a.rr_mvs) * a.rr_mvs + (a.r_mvs <= a.rr_mvs) * a.r_mvs;
	b_low = (b.r_mvs > b.rr_mvs) * b.rr_mvs + (b.r_mvs <= b.rr_mvs) * b.r_mvs;
	ind = a_low + b_low;
	if (r_cmb <= rr_cmb && r_cmb < ind)
	{
		save_moves(a, b, 0, save_iter);
		return (r_cmb);
	}
	if (rr_cmb < r_cmb && rr_cmb < ind)
	{
		save_moves(a, b, 1, save_iter);
		return (rr_cmb);
	}
	save_moves(a, b, 2, save_iter);
	return (ind);
}

int	find_steps(t_vars *vr, int a_index, int value, t_moves *save_iter)
{
	t_scores	a;
	t_scores	b;
	int			b_index;
	int			moves;

	a.r_mvs = a_index;
	a.rr_mvs = ft_nodesize(vr->a_stk) - a_index;
	b_index = find_under(value, vr, -1, 0);
	b.r_mvs = b_index;
	b.rr_mvs = ft_nodesize(vr->b_stk) - b_index;
	moves = best_comb_rotations(a, b, save_iter);
	return (moves);
}
