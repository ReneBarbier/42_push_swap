/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:22:08 by rbarbier          #+#    #+#             */
/*   Updated: 2024/01/09 12:47:17 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_position(int value, t_vars *vr, int i, int low_index)
{
	t_node	*iterator;
	int		high_index;
	int		high_value;
	int		low_value;

	high_value = value;
	iterator = vr->a_stk;
	low_value = INT32_MAX;
	while (iterator)
	{
		if (iterator->content > value && iterator->content < low_value)
		{
			low_value = iterator->content;
			low_index = i;
		}
		if (iterator->content < high_value)
			high_index = i;
		if (iterator->content < high_value)
			high_value = iterator->content;
		iterator = iterator->next;
		i++;
	}
	if (low_index == -1)
		return (high_index);
	return (low_index);
}

void	biggest_to_top(t_vars *vr, int j, double i)
{
	t_node	*iterator;
	double	big_ind;
	int		big_value;
	int		steps;

	iterator = vr->b_stk;
	big_value = iterator->content;
	while (iterator)
	{
		if (iterator->content > big_value)
		{
			big_ind = i;
			big_value = iterator->content;
		}
		iterator = iterator->next;
		i += 1;
	}
	steps = big_ind - (((i / 2) <= big_ind) * (big_ind - (i / 2)) * 2);
	while (j++ < steps)
	{
		if (big_ind <= i / 2)
			rb(vr);
		else
			rrb(vr);
	}
}

void	lowest_to_top(t_vars *vr, int j, double i)
{
	t_node	*iterator;
	double	low_ind;
	int		low_value;
	int		steps;

	iterator = vr->a_stk;
	low_value = INT_MAX;
	while (iterator)
	{
		if (iterator->content <= low_value)
		{
			low_ind = i;
			low_value = iterator->content;
		}
		iterator = iterator->next;
		i += 1;
	}
	steps = low_ind - (((i / 2) <= low_ind) * (low_ind - (i / 2)) * 2);
	while (j++ < steps)
	{
		if (low_ind <= i / 2)
			ra(vr);
		else
			rra(vr);
	}
}
