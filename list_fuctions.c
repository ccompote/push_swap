/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fuctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:34:06 by ccompote          #+#    #+#             */
/*   Updated: 2022/11/30 19:44:15 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_last(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return(head);
}

void add_back(t_list *head, t_list *to_add)
{
	t_list *last;
	
	if (!head)
	{
		head = to_add;
		return ;
	}	
	last = get_last(head);
	last->next = to_add;
}

t_list	*new_list(int value)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return(NULL);
	res->value = value;
	res->next = NULL;
	return (res);
}

t_list	*swap_first_two(t_list *head)
{
	t_list	*temp;
	
	temp = head->next;
	if (!temp)
		return(head);
	head->next = head->next->next;
	temp->next = head;
	return (temp);
}

t_list	*rotate(t_list *head)
{
	t_list	*new_head;
	t_list *last;

	new_head = head->next;
	if (!new_head)
		return(head);
	last = get_last(head);
	last->next = head;
	head->next = NULL;
	return (new_head);
}

t_list	*rotate_reverse(t_list *head)
{
	t_list *new_head;
	t_list *next_to_last;

	next_to_last = head;
	if (!head->next)
		return (head);
	while (next_to_last->next->next)
		next_to_last = next_to_last->next;
	new_head = next_to_last->next;
	new_head->next = head;
	next_to_last->next = NULL;
	return (new_head);
}

void print_list(t_list *head)
{
	t_list *temp;
	temp = head;
	while(head)
	{
		ft_putstr(ft_itoa(head->value));
		ft_putstr("->");
		head = head->next;
	}
	ft_putstr("null\n");
	head = temp;
}

void print_list_steps(t_list *head)
{
	t_list *temp;
	temp = head;
	while(head)
	{
		ft_putstr(ft_itoa(head->steps));
		ft_putstr(", ");
		head = head->next;
	}
	pc(127);
	pc(127);
	pc('\n');
	head = temp;
}