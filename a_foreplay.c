/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_foreplay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:01:44 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/15 20:00:08 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_b(t_list **head_a)
{
	t_list	*head_b;
	t_list	*temp;
	t_list	*other_temp;
	t_list	*yet_another_temp;
	int		minim;
	int		maxim;
	int		med;
	int		counter;

	temp = *head_a;
	other_temp = *head_a;
	minim = MAX_INT;
	maxim = MIN_INT;
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
	counter = list_len(other_temp);
	if ((*head_a)->steps == -1)
	{
		return (NULL);
	}
	while (counter--)
	{
		if (other_temp->value != minim && other_temp->value != maxim
			&& other_temp->value != med)
			pb(&other_temp, &head_b);
		else
			ra(&other_temp);
	}
	*head_a = other_temp;
	return (head_b);
}
