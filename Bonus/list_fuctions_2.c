/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fuctions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:47:50 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/20 20:36:50 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	rotate(t_list **head)
{
	t_list	*new_head;
	t_list	*last;
	t_list	*other_temp;

	other_temp = *head;
	new_head = other_temp->next;
	if (!new_head)
		return ;
	last = get_last(other_temp);
	last->next = other_temp;
	other_temp->next = NULL;
	*head = new_head;
}

void	rotate_reverse(t_list **head)
{
	t_list	*new_head;
	t_list	*next_to_last;
	t_list	*other_temp;

	other_temp = *head;
	next_to_last = other_temp;
	if (!other_temp->next)
		return ;
	while (next_to_last->next->next)
		next_to_last = next_to_last->next;
	new_head = next_to_last->next;
	new_head->next = other_temp;
	next_to_last->next = NULL;
	*head = new_head;
}

void	print_list(t_list *head)
{
	t_list	*temp;
	char	*text;

	temp = head;
	while (head)
	{
		text = ft_itoa(head->value);
		ft_putstr(text);
		ft_putstr("->");
		free(text);
		head = head->next;
	}
	ft_putstr("null\n");
	head = temp;
}

void	print_list_steps(t_list *head)
{
	t_list	*temp;
	char	*text;

	temp = head;
	while (head)
	{
		text = ft_itoa(head->steps);
		ft_putstr(text);
		ft_putstr(", ");
		free(text);
		head = head->next;
	}
	pc('\n');
	head = temp;
}

void	push_first_from_b_to_a(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	*b = temp->next;
	temp->next = *a;
	*a = temp;
}
