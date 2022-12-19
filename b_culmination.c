/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_culmination.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:05:12 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/19 22:23:58 by ccompote         ###   ########.fr       */
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

void	f1(t_list *b, t_list **head_a, t_list **head_b)
{
	int	iter;

	iter = b->cur_pos_a;
	while (iter)
	{
		rr(head_a, head_b);
		iter--;
	}
	iter = b->cur_pos_b - b->cur_pos_a;
	while (iter)
	{
		rb(head_b);
		iter--;
	}
	pa(head_a, head_b);
}

void	f2(t_list *b, t_list **head_a, t_list **head_b)
{
	int	iter;

	iter = b->cur_pos_b;
	while (iter)
	{
		rr(head_a, head_b);
		iter--;
	}
	iter = b->cur_pos_a - b->cur_pos_b;
	while (iter)
	{
		ra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

void	f3(t_list *a, t_list *b, t_list **head_a, t_list **head_b)
{
	int	iter;

	iter = list_len(a) - b->cur_pos_a;
	while (iter)
	{
		rrr(head_a, head_b);
		iter--;
	}
	iter = list_len(*head_b) - b->cur_pos_b
		- list_len(*head_a) + b->cur_pos_a;
	while (iter)
	{
		rrb(head_b);
		iter--;
	}
	pa(head_a, head_b);
}

void	f4(t_list *b, t_list **head_a, t_list **head_b)
{
	int	iter;

	iter = list_len(*head_b) - b->cur_pos_b;
	while (iter)
	{
		rrr(head_a, head_b);
		iter--;
	}
	iter = list_len(*head_a) - b->cur_pos_a
		- list_len(*head_b) + b->cur_pos_b;
	while (iter)
	{
		rra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

void	f5(t_list *a, t_list *b, t_list **head_a, t_list **head_b)
{
	int	iter;

	iter = b->cur_pos_b;
	while (iter)
	{
		rb(head_b);
		iter--;
	}
	iter = list_len(a) - b->cur_pos_a;
	while (iter)
	{
		rra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

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

void	push_best_b_to_a(t_list **head_a, t_list **head_b, t_list *a, t_list *b)
{
	t_list	*temp;
	int		min_steps;
	int		cur_pos_b;

	temp = *head_b;
	min_steps = find_min_steps(b);
	cur_pos_b = 0;
	while (temp)
	{	
		if (b->steps == min_steps)
		{
			if (min_steps == max(b->cur_pos_a, b->cur_pos_b) + 1)
				f7(b, head_a, head_b);
			else if (min_steps == max(list_len(a)
					- b->cur_pos_a, list_len(*head_b) - b->cur_pos_b) + 1)
				f8(a, b, head_a, head_b);
			else if (min_steps == b->cur_pos_b + list_len(a) - b->cur_pos_a + 1)
				f5(a, b, head_a, head_b);
			else if (min_steps == b->cur_pos_a
				+ list_len(*head_b) - b->cur_pos_b + 1)
				f6(b, head_a, head_b);
			return ;
		}
		b = b->next;
	}
}

int	find_index_of_min(t_list *temp)
{
	int	index;
	int	i;
	int	counter;

	i = MAX_INT;
	index = 0;
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
	return (index);
}

void	final_rotate(t_list **head_a)
{
	t_list	*temp;
	int		index;

	temp = *head_a;
	index = find_index_of_min(temp);
	if (index < list_len(*head_a) - index)
	{
		while (index--)
			ra(head_a);
	}
	else
	{
		index = list_len(*head_a) - index;
		while (index--)
			rra(head_a);
	}
}

void	initial_swap(t_list **head_a)
{
	t_list	*a;

	if (list_len(*head_a) != 3)
		return ;
	a = *head_a;
	if ((a->value < a->next->value && a->value < a->next->next->value
			&& a->next->value > a->next->next->value)
		|| (a->value > a->next->value
			&& a->value < a->next->next->value
			&& a->next->value < a->next->next->value)
		|| (a->value > a->next->value && a->value > a->next->next->value
			&& a->next->value > a->next->next->value))
		sa(head_a);
}

void	sort(t_list **head_a, t_list **head_b)
{
	t_list	*a;
	t_list	*b;

	a = *head_a;
	b = *head_b;
	initial_swap(&a);
	while (b)
	{
		steps(a, b);
		push_best_b_to_a(&a, &b, a, b);
	}
	final_rotate(&a);
	*head_a = a;
	*head_b = b;
}
