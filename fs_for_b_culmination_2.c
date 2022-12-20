/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_for_b_culmination_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:04:37 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/20 16:43:27 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f6(t_list *b, t_list **head_a, t_list **head_b)
{
	int	iter;

	iter = list_len(*head_b) - b->cur_pos_b;
	while (iter)
	{
		rrb(head_b);
		iter--;
	}
	iter = b->cur_pos_a;
	while (iter)
	{
		ra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

void	f7(t_list *b, t_list **head_a, t_list **head_b)
{
	if (b->cur_pos_a < b->cur_pos_b)
		f1(b, head_a, head_b);
	else
		f2(b, head_a, head_b);
}

void	f8(t_list *a, t_list *b, t_list **head_a, t_list **head_b)
{
	if (list_len(a) - b->cur_pos_a
		< list_len(*head_b) - b->cur_pos_b)
		f3(a, b, head_a, head_b);
	else
		f4(b, head_a, head_b);
}

int	ll(int cur_pos_b, int cur_pos_a, t_list *head_b, t_list *temp)
{
	return (min(min(max(cur_pos_b, cur_pos_a),
				max(list_len(head_b), list_len(temp))),
			min(cur_pos_b + list_len(temp),
				cur_pos_a + list_len(head_b))) + 1);
}

void	oll(t_list *head_b, t_list *temp, int cur_pos_a, int cur_pos_b)
{
	head_b->steps = ll(cur_pos_b, cur_pos_a, head_b, temp);
	head_b->cur_pos_a = cur_pos_a;
	head_b->cur_pos_b = cur_pos_b;
}
