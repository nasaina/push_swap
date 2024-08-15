/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:30:54 by nandrian          #+#    #+#             */
/*   Updated: 2024/07/29 17:00:24 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf.h"
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

int		check_digit(int ac, char **av, t_stack *stack);
int		check_double(t_stack *stack);
int		count_nb(t_stack *stack);
int		get_target(t_stack *stack, int ref);
int		get_target_a(t_stack *stack, int ref);
int		get_index(t_stack *stack, int ref);
int		check_median(t_stack *stack);
int		check_move(t_stack *stack, int ref);
int		count_move(t_stack *stack_a, t_stack *stack_b, int ref);
int		move_min(t_stack *stack_a, t_stack *stack_b);
t_stack	*create(int n);
void	add_back(t_stack **stack, int n);
void	add_front(t_stack **stack, int n);
t_stack	*lst_last(t_stack *stack);
void	free_stack(t_stack *stack);
void	make_sort(t_stack **stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack	**stack_b);
void	pb(t_stack **stack_a, t_stack	**stack_b);
void	do_rrr(t_stack **stack_a, int a, t_stack **stack_b, int b);
void	do_rr(t_stack **stack_a, int a, t_stack **stack_b, int b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
int		sorted(t_stack *stack);
void	sort_three(t_stack **stack);
void	sort(t_stack **stack);
long	ft_atol(const char *str, t_stack *stack);
int		check_max(t_stack *stack);
int		check_min(t_stack *stack);
int		check_pos_min(t_stack *stack);
int		check_pos_max(t_stack *stack);
t_stack	*detach_first(t_stack **stack);
t_stack	*detach_last(t_stack **stack);
void	ft_print_error(t_stack *stack);
void	free_stack(t_stack *stack);

#endif