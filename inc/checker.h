/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:30:40 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/08 12:13:10 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "../bonus/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/mandatory/inc/ft_printf.h"

typedef struct s_node
{
	int				index;
	int				content;
	struct s_node	*next;
}	t_node;

typedef struct s_vars
{
	t_node	*a_stk;
	t_node	*b_stk;
	int		n_num;
}	t_vars;

void	s(t_node **stak);
void	ss(t_node **stak_a, t_node **stak_b);
void	p(t_node **from, t_node **to);
void	r(t_node **stak);
void	rrx(t_node **stak);
t_node	*ft_nodenew(int content);
t_node	*ft_nodelast(t_node *lst);
void	ft_nodeadd_back(t_node **lst, t_node *new);
int		ft_nodesize(t_node *lst);
void	ft_nodeadd_front(t_node **lst, t_node *new);
void	input_check(int num, char **argv, t_vars *vr);
void	error_finish(void);
long	ft_atol(char *str);

#endif