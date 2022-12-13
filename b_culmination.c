/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_culmination.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:05:12 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/11 20:18:44 by ccompote         ###   ########.fr       */
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
	int		cur_pos_a;
	int		cur_pos_b;
	t_list	*temp;

	cur_pos_b = 0;
	if (!head_b)
		return ;
	while (head_b)
	{
		temp = head_a;
		if ((get_last(temp)->value < head_b->value)
			&& (temp->value > head_b->value))
		{
			head_b->steps = min(min(max(cur_pos_b, 0),
			max(list_len(head_b), list_len(temp))),
			min(cur_pos_b + list_len(temp),
			list_len(head_b))) + 1;
			head_b->cur_pos_a = 0;
			head_b->cur_pos_b = cur_pos_b;
		}
			// in case we need to put element from b to zero position in a
			
		cur_pos_a = 1;
		while (temp->next)
		{
			if ((temp->value < head_b->value)
				&& (temp->next->value > head_b->value))
			{
				head_b->steps = min(min(max(cur_pos_b, cur_pos_a),
				max(list_len(head_b), list_len(temp->next))),
				min(cur_pos_b + list_len(temp->next), cur_pos_a +
				list_len(head_b))) + 1;
				head_b->cur_pos_a = cur_pos_a;
				head_b->cur_pos_b = cur_pos_b;
			}
			temp = temp->next;
			cur_pos_a++;
		}
		head_b = head_b->next;
		cur_pos_b++;
	}
}


// A: 1 8 10 100 -20
// B: -1 3 2 4 5 7 9 66 38

// A: 100 -20
// B: -1 3 2 4 5 7 9 66 38

// cur_postion_a - amount of steps we need to rotate a to left
// cur_postion_b - amount of steps we need to rotate b to left
//list_len(a) amount of steps we need to rotate a to right
//list_len(b) amount of steps we need to rotate b to right
//(max(cur_pos_b, cur_pos_a) - how much needs to be rotated to left
//max(list_len(head_b), list_len(temp->next)) how much needs to be rotated to right
//cur_pos_b + list_len(temp->next) rotating b to left, a to right
//cur_pos_a + list_len(head_b) rotating b to right, a to left

int find_min_steps(t_list *b)
{
	int	min_steps;

	min_steps = 2147483647;
	while (b)
	{
		if (b->steps < min_steps)
			min_steps = b->steps;
		b = b->next;
	}
	return (min_steps);
}

void	push_best_b_to_a(t_list **head_a, t_list **head_b)
{
	t_list *a;
	t_list *b;
	t_list	*temp;
	int min_steps;
	int	cur_pos_a;
	int	cur_pos_b;
	int iter;

	a = *head_a;
	b = *head_b;
	min_steps = find_min_steps(b);
	cur_pos_b = 0;
	while (head_b)
	{	
		temp = a;
		if (b->steps == min_steps)
		{
			// rotating both left
			if (min_steps == max(b->cur_pos_a, b->cur_pos_b) + 1)
			{
				if (b->cur_pos_a < b->cur_pos_b)
				{
					iter = b->cur_pos_a;
					while (iter)
					{
						rr(&a, &b);
						iter--;
					}
					iter = b->cur_pos_b - b->cur_pos_a;
					while (iter)
					{
						rb(&b);
						iter--;
					}
					pa(&a, &b);
				}
				else
				{
					iter = b->cur_pos_b;
					while (iter)
					{
						rr(&a, &b);
						iter--;
					}
					iter = b->cur_pos_a - b->cur_pos_b;
					while (iter)
					{
						ra(&a);
						iter--;
					}
					pa(&a, &b);
				}
			}
			//rotate both right
			else if(min_steps == max(list_len(a) - b->cur_pos_a, list_len(*head_b) - b->cur_pos_b) + 1)
			{
				if (list_len(a) - b->cur_pos_a < list_len(*head_b) - b->cur_pos_b)
				{
					iter = list_len(a) - b->cur_pos_a;
					while (iter)
					{
						rrr(&a, &b);
						iter--;
					}
					iter = list_len(*head_b) - b->cur_pos_b - list_len(a) - b->cur_pos_a;
					while (iter)
					{
						rrb(&b);
						iter--;
					}
					pa(&a, &b);
				}
				else
				{
					iter = list_len(*head_b) - b->cur_pos_b;
					while (iter)
					{
						rrr(&a, &b);
						iter--;
					}
					iter = list_len(a) - b->cur_pos_a - list_len(*head_b) - b->cur_pos_b;
					while (iter)
					{
						rra(&a);
						iter--;
					}
					pa(&a, &b);
				}
			}
			//rotate b to left, a to right
			else if (min_steps == b->cur_pos_b + list_len(a) - b->cur_pos_a + 1)
			{
				iter = b->cur_pos_b;
				while (iter)
				{
					rb(&b);
					iter--;
				}
				iter = list_len(a) - b->cur_pos_a;
				while (iter)
				{
					rra(&a);
					iter--;
				}
				pa(&a, &b);
			}
			//rotate b to right a to left
			else if (min_steps == b->cur_pos_a + list_len(*head_b) - b->cur_pos_b + 1)
			{
				iter = list_len(*head_b) - b->cur_pos_b;
				while (iter)
				{
					rrb(&b);
					iter--;
				}
				iter = b->cur_pos_a;
				while (iter)
				{
					ra(&a);
					iter--;
				}
				pa(&a, &b);
			}
			*head_a = a;
			*head_b = b;
			return ;
		}
		b = b->next;
	}
}

void final_rotate(t_list **head_a)
{
	t_list	*temp;
	int i;
	int	index;
	int	counter;

	i = 2147483647;
	index = 0;
	temp = *head_a;
	counter = 0;
	while (temp)
	{
		if (temp->value < i)
		{
			i = temp->value;
			index = counter;
		}
		counter++;
		temp = temp->next;
	}
	if (index < list_len(*head_a) - index)
	{
		while (index)
		{
			ra(head_a);
			index--;
		}
	}
	else
	{
		index = list_len(*head_a) - index;
		while (index)
		{
			rra(head_a);
			index--;
		}
	}
	
}

/*
1 2 3
2 3 1
3 1 2

1 3 2
2 1 3
3 2 1
*/
void initial_swap(t_list **head_a)
{
	t_list *a;

	if (list_len(*head_a) != 3)
		return ;
	a = *head_a;
	if (a->value < a->next->value && a->value < a->next->next->value && a->next->value > a->next->next->value
		|| a->value > a->next->value && a->value < a->next->next->value && a->next->value < a->next->next->value
		|| a->value > a->next->value && a->value > a->next->next->value && a->next->value > a->next->next->value
		)
		sa(head_a);
}

void	sort(t_list **head_a, t_list **head_b)
{
	t_list *a;
	t_list *b;

	a = *head_a;
	b = *head_b;
	initial_swap(&a);
	while (b)
	{
		steps(a, b);
		push_best_b_to_a(&a, &b);
	}
	final_rotate(&a);
	*head_a = a;
	*head_b = b;
}

