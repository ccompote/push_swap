/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_for_b_culmination.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:57:18 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/23 15:57:22 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_list *head)
{
	t_list	*temp;
	int		res;

	res = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		res++;
	}
	return (res);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	steps(t_list *head_a, t_list *head_b)
{
	int		cur_pos_a;
	int		cur_pos_b;
	t_list	*temp;

	cur_pos_b = 0;
	while (head_b)
	{
		temp = head_a;
		if ((get_last(temp)->value < head_b->value)
			&& (temp->value > head_b->value))
			oll(head_b, temp, 0, cur_pos_b);
		cur_pos_a = 1;
		while (temp->next)
		{
			if ((temp->value < head_b->value)
				&& (temp->next->value > head_b->value))
				oll(head_b, temp->next, cur_pos_a, cur_pos_b);
			temp = temp->next;
			cur_pos_a++;
		}
		head_b = head_b->next;
		cur_pos_b++;
	}
}

int	find_min_steps(t_list *b)
{
	int	min_steps;

	min_steps = MAX_INT;
	while (b)
	{
		if (b->steps < min_steps)
			min_steps = b->steps;
		b = b->next;
	}
	return (min_steps);
}
