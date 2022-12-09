/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:22:13 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/07 19:52:30 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head)
{
	swap_first_two(head);
	write(1, "sa\n", 3);
}

void	sb(t_list **head)
{
	swap_first_two(head);
	write(1, "sb\n", 3);
}

void	ss(t_list **head_a, t_list **head_b)
{
	swap_first_two(head_b);
	swap_first_two(head_a);
	write(1, "ss\n", 3);
}

void	ra(t_list **head)
{
	rotate(head);
	write(1, "ra\n", 3);
}

void	rb(t_list **head)
{
	rotate(head);
	write(1, "rb\n", 3);
}

void	rra(t_list **head)
{
	rotate_reverse(head);
	write(1, "rra\n", 4);
}

void	rrb(t_list **head)
{
	rotate_reverse(head);
	write(1, "rrb\n", 4);
}

void	rr(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
	write(1, "rr\n", 3);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	rotate_reverse(head_a);
	rotate_reverse(head_b);
	write(1, "rrr\n", 4);
}

void	pa(t_list **head_a, t_list **head_b)
{
	push_first_from_b_to_a(head_a, head_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **head_a, t_list **head_b)
{
	push_first_from_b_to_a(head_b, head_a);
	write(1, "pb\n", 3);
}