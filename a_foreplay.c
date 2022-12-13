/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_foreplay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:01:44 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/11 20:08:10 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>



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

t_list	*push_b(t_list **head_a)
{
	t_list	*head_b;
	t_list	*temp;
	t_list	*other_temp;
	t_list 	*yet_another_temp;
	int 	minim;
	int 	maxim;
	int		med;

	temp = *head_a;
	other_temp = *head_a;
	minim = 2147483647;
	maxim = -2147483648;
	while (temp)
	{
		if (temp->value > maxim)
			maxim = temp->value;
		if (temp->value < minim)
			minim = temp->value;
		temp = temp->next;
	}
	temp = other_temp;
	head_b = NULL;
	yet_another_temp = NULL;
	temp = NULL;
	med = find_median(*head_a);
	if ((*head_a)->steps == -1)
	{
		return (NULL);
	}
	while (other_temp)
	{
		if (other_temp->value != minim && other_temp->value != maxim && other_temp->value != med)
			pb(&other_temp, &head_b);
		else
			push_first_from_b_to_a(&yet_another_temp, &other_temp);
	}
	*head_a = yet_another_temp;
	return (head_b);
}

