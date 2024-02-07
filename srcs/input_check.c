/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:26:56 by rbarbier          #+#    #+#             */
/*   Updated: 2024/01/10 19:17:37 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	check_dups(t_node **a_stak)
{
	t_node	*cur_node;
	t_node	*cmp;

	cur_node = *a_stak;
	while (cur_node->next)
	{
		cmp = cur_node->next;
		while (cmp)
		{
			if (cmp->content == cur_node->content)
				error_finish();
			cmp = cmp->next;
		}
		cur_node = cur_node->next;
	}
}

static void	check_valid_num(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		if ((argv[j][i] == '-' || argv[j][i] == '+') && !argv[j][i + 1])
			error_finish();
		if (argv[j][i] == '-' || argv[j][i] == '+')
			i++;
		while (ft_isdigit(argv[j][i]))
			i++;
		if (argv[j][i])
			error_finish();
		j++;
		i = 0;
	}
}

void	input_check(int num, char **argv, t_vars *vr)
{
	t_node	*tmp;
	int		j;
	long	hold;

	j = 1;
	if (num == 0)
		exit(0);
	while (j < num + 1)
		if (!argv[j++][0])
			error_finish();
	j = 0;
	vr->n_num = num;
	check_valid_num(argv);
	while (argv[++j])
	{
		hold = ft_atol(argv[j]);
		if (hold > 2147483647 || hold < -2147483648)
			error_finish();
		tmp = ft_nodenew((int)hold);
		if (!tmp)
			error_finish();
		ft_nodeadd_back(&(vr->a_stk), tmp);
	}
	check_dups(&(vr->a_stk));
}
