/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:39:44 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/11 12:49:36 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_finish(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_vars vr)
{
	while (vr.a_stk->next)
	{
		if (vr.a_stk->content > vr.a_stk->next->content)
			return (1);
		vr.a_stk = vr.a_stk->next;
	}
	if (vr.b_stk)
		return (1);
	return (0);
}
/*
void	print_status(t_vars vr)
{
	while (vr.a_stk || vr.b_stk)
	{
		if (vr.a_stk)
		{
			ft_printf("\033[0;36m%d   \033[0m", vr.a_stk->content);
			vr.a_stk = vr.a_stk->next;
		}
		else
			ft_printf("    ");
		if (vr.b_stk)
		{
			ft_printf("\033[0;33m%d\n\033[0m", vr.b_stk->content);
			vr.b_stk = vr.b_stk->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n");
}
*/