/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fuctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:34:06 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/09 18:20:53 by ccompote         ###   ########.fr       */
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

void	swap_first_two(t_list **head)
{
	t_list	*temp;
	t_list	*other_temp;

	other_temp = *head;	
	temp = other_temp->next;

	if (!temp)
		return ;
	other_temp->next = other_temp->next->next;
	temp->next = other_temp;
	*head = temp;
	
}

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

void print_list(t_list *head)
{
	t_list	*temp;
	
	temp = head;
	while (head)
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
	t_list	*temp;
	
	temp = head;
	while (head)
	{
		ft_putstr(ft_itoa(head->steps));
		ft_putstr(", ");
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

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int find_median(t_list *head)
{
	int *res;
	int i;
	res = malloc(sizeof(int) * list_len(head));
	while (head)
	{
		res[i] = head->value;
		i++;
		head = head->next;
	}
	selectionSort(res, i);
	i = res[i / 2];
	free(res);
	return(i);
}