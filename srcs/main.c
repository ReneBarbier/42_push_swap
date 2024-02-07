/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:20:10 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/11 12:44:40 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_vars	vr;

	input_check(argc - 1, argv, &vr);
	if (is_sorted(vr))
		sort_stak(&vr);
	exit(0);
}
