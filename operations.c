/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:22:13 by ccompote          #+#    #+#             */
/*   Updated: 2022/11/30 19:47:25 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *sa(t_list *head)
{
	head = swap_first_two(head);
	write(1, "sa\n", 3);
	return (head);
}

t_list *sb(t_list *head)
{
	head = swap_first_two(head);
	write(1, "sb\n", 3);
	return (head);
}

t_list **ss(t_list *head_a, t_list *head_b)
{
	t_list **res;

	res = malloc(sizeof(t_list) * 2);
	head_b = swap_first_two(head_b);
	write(1, "ss\n", 3);
	res[0] = head_a;
	res[1] = head_b;
	return (res);
}

t_list *ra(t_list *head)
{
	head = rotate(head);
	write(1, "ra\n", 3);
	return (head);
}

t_list *rb(t_list *head)
{
	head = rotate(head);
	write(1, "rb\n", 3);
	return (head);
}

t_list *rra(t_list *head)
{
	head = rotate_reverse(head);
	write(1, "rra\n", 4);
	return (head);
}

t_list *rrb(t_list *head)
{
	head = rotate_reverse(head);
	write(1, "rrb\n", 4);
	return (head);
}

t_list **rr(t_list *head_a, t_list *head_b)
{
	t_list **res;
	
	res = malloc(sizeof(t_list) * 2);
	head_a = rotate(head_a);
	head_b = rotate(head_b);
	write(1, "rr\n", 3);
	res[0] = head_a;
	res[1] = head_b;
	return (res);
}

t_list **rrr(t_list *head_a, t_list *head_b)
{
	t_list **res;
	
	res = malloc(sizeof(t_list) * 2);
	head_a = rotate_reverse(head_a);
	head_b = rotate_reverse(head_b);
	write(1, "rrr\n", 4);
	res[0] = head_a;
	res[1] = head_b;
	return (res);
}