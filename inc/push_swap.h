/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:20:55 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/08 12:13:53 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/mandatory/inc/ft_printf.h"
# include <limits.h>

typedef struct s_node
{
	int				index;
	int				content;
	struct s_node	*next;
}	t_node;

typedef struct s_scores
{
	int	r_mvs;
	int	rr_mvs;
	int	cheapest;
	int	index_chp;
}	t_scores;

typedef struct s_vars
{
	t_node	*a_stk;
	t_node	*b_stk;
	int		n_num;
}	t_vars;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rs;
	int	rra;
	int	rrb;
	int	rrs;
}	t_moves;

long	ft_atol(char *str);
t_node	*ft_nodenew(int content);
void	ft_nodeadd_back(t_node **lst, t_node *new);
int		ft_nodesize(t_node *lst);
t_node	*ft_nodelast(t_node *lst);
void	ft_nodeadd_front(t_node **lst, t_node *new);
void	error_finish(void);
void	input_check(int num, char **argv, t_vars *vr);
void	sa(t_vars *vr);
void	sb(t_vars *vr);
void	pa(t_vars *vr);
void	pb(t_vars *vr);
void	ra(t_vars *vr);
void	rb(t_vars *vr);
void	rs(t_vars *vr);
void	rra(t_vars *vr);
void	rrb(t_vars *vr);
void	rrs(t_vars *vr);
void	sort_stak(t_vars *vr);
int		is_sorted(t_vars vr);
void	algorithm(t_vars *vr);
void	print_status(t_vars vr);
void	tree_case(t_vars *vr);
int		find_steps(t_vars *vr, int a_index, int value, t_moves *save_iter);
int		best_comb_rotations(t_scores a, t_scores b, t_moves *save_iter);
void	save_moves(t_scores a, t_scores b, int mode, t_moves *save_iter);
int		find_under(int value, t_vars *vr, int low_index, int i);
void	lowest_to_top(t_vars *vr, int j, double i);
void	biggest_to_top(t_vars *vr, int j, double i);
int		find_position(int value, t_vars *vr, int i, int low_index);
int		diff_zero(int a, int b, int mode);

#endif