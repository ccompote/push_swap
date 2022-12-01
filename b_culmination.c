/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_culmination.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:05:12 by ccompote          #+#    #+#             */
/*   Updated: 2022/11/30 20:18:23 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	int		curr_pos_a;
	int		curr_pos_b;
	t_list	*temp;

	curr_pos_b = 0;
	while (head_b)
	{
		temp = head_a;
		if ((get_last(temp)->value < head_b->value)
			&& (temp->value > head_b->value))
			{head_b->steps = min(min(max(curr_pos_b, 0),
			max(list_len(head_b), list_len(temp))),
			min(curr_pos_b + list_len(temp),
			list_len(head_b))) + 1;printf("condition\n");}
		curr_pos_a = 1;
		while (temp->next)
		{
			if ((temp->value < head_b->value)
				&& (temp->next->value > head_b->value))
				head_b->steps = min(min(max(curr_pos_b, curr_pos_a),
				max(list_len(head_b), list_len(temp->next))),
				min(curr_pos_b + list_len(temp->next), curr_pos_a +
				list_len(head_b))) + 1;
			temp = temp->next;
			curr_pos_a++;
		}
		head_b = head_b->next;
		curr_pos_b++;
	}
}


// A: 1 8 10 100 -20
// B: -1 3 2 4 5 7 9 66 38