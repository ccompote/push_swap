/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_foreplay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:01:44 by ccompote          #+#    #+#             */
/*   Updated: 2022/11/30 20:16:36 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list **push_first_from_b_to_a(t_list *head_a, t_list *head_b)
{
	t_list **res;
	t_list *temp;

	res = malloc(sizeof(t_list) * 2);
	temp = head_b;
	head_b = head_b->next;
	temp->next = head_a;
	
	res[0] = temp;
	res[1] = head_b;
	return (res);
}

/* t_list	*func1(t_list *head_a, int b)
{
	static t_list *head_b;
	t_list *temp;
	print_list(head_a);
	if(!b){
	if (!head_b)
	{
		head_b = head_a;
		head_a = head_a->next;
		print_list(head_a);
		head_b->next = NULL;
		print_list(head_a);
	}
	else
	{
		temp = head_a;
		add_back(head_b, temp);
		// head_a = head_a->next;
		temp->next = NULL;
	}}
	return (head_b);
} */

t_list	*push_b(t_list *head_a)
{
	t_list	*head_b;
	t_list	*temp;
	t_list	*other_temp;
	int minim;
	int maxim;

	head_b = head_a;
	minim = 2147483647;
	maxim = -2147483648;
	while (head_a)
	{
		if (head_a->value > maxim)
			maxim = head_a->value;
		if (head_a->value < minim)
			minim = head_a->value;
		head_a = head_a->next;
	}
	head_a = head_b;
	head_b = NULL;
	other_temp = NULL;
	temp = NULL;
	while (head_a)
	{
		if (head_a->value != minim && head_a->value != maxim)
		{
			if (!head_b)
			{
				head_b = head_a;
				head_a = head_a->next;
				head_b->next = NULL;
			}
			else
			{
				temp = head_a;
				add_back(head_b, temp);
				head_a = head_a->next;
				temp->next = NULL;
			}
		}
		else
		{
			if (!other_temp)
			{
				other_temp = head_a;
				head_a = head_a->next;
				other_temp->next = NULL;
			}
			else
			{
				add_back(other_temp, head_a);
				head_a = head_a->next;
				other_temp->next->next = NULL;
			}
		}
	}
	head_a = other_temp;
	return (head_b);
}
