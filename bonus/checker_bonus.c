/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:08:29 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/08 12:10:57 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../inc/checker.h"

void	rrr(t_node **stak_a, t_node **stak_b)
{
	rrx(stak_a);
	rrx(stak_b);
}

void	rr(t_node **stak_a, t_node **stak_b)
{
	r(stak_a);
	r(stak_b);
}

void	move(char *read, t_vars *vr)
{
	if (!ft_strncmp("sa\n", read, 5))
		s(&vr->a_stk);
	else if (!ft_strncmp("sb\n", read, 5))
		s(&vr->b_stk);
	else if (!ft_strncmp("ss\n", read, 5))
		ss(&vr->a_stk, &vr->b_stk);
	else if (!ft_strncmp("ra\n", read, 5))
		r(&vr->a_stk);
	else if (!ft_strncmp("rb\n", read, 5))
		r(&vr->b_stk);
	else if (!ft_strncmp("rr\n", read, 5))
		rr(&vr->a_stk, &vr->b_stk);
	else if (!ft_strncmp("pa\n", read, 5))
		p(&vr->b_stk, &vr->a_stk);
	else if (!ft_strncmp("pb\n", read, 5))
		p(&vr->a_stk, &vr->b_stk);
	else if (!ft_strncmp("rra\n", read, 5))
		rrx(&vr->a_stk);
	else if (!ft_strncmp("rrb\n", read, 5))
		rrx(&vr->b_stk);
	else if (!ft_strncmp("rrr\n", read, 5))
		rrr(&vr->b_stk, &vr->a_stk);
	else
		error_finish();
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

int	main(int argc, char **argv)
{
	t_vars	vr;
	char	*read;

	input_check(argc, argv, &vr);
	read = get_next_line(STDIN_FILENO);
	if (read)
	{
		while (ft_strlen(read))
		{
			move(read, &vr);
			read = get_next_line(STDIN_FILENO);
			if (!read)
				break ;
		}
	}
	if (!is_sorted(vr))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit(1);
}
