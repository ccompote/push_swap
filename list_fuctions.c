/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fuctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:34:06 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/19 22:27:44 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_last(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	add_back(t_list *head, t_list *to_add)
{
	t_list	*last;

	if (!head)
	{
		head = to_add;
		return ;
	}	
	last = get_last(head);
	last->next = to_add;
}

void	add_front(t_list **head, t_list *to_add)
{
	to_add->next = *head;
	*head = to_add;
}

t_list	*new_list(int value)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
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

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	selection_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap(&arr[min_idx], &arr[i]);
		i++;
	}
}

int	find_median(t_list *head)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * list_len(head));
	if (!res)
	{
		head->steps = -1;
		return (0);
	}
	while (head)
	{
		res[i] = head->value;
		i++;
		head = head->next;
	}
	selection_sort(res, i);
	i = res[i / 2];
	free(res);
	return (i);
}

int	check_repetitions(t_list *head)
{
	int	*res;
	int	i;
	int	len;

	i = 0;
	len = list_len(head);
	res = malloc(sizeof(int) * len);
	if (!res)
		return (0);
	while (head)
	{
		res[i++] = head->value;
		head = head->next;
	}
	selection_sort(res, i);
	i = 0;
	while (++i < len)
	{
		if (res[i] == res[i - 1])
			return (free(res), 0);
	}
	free(res);
	return (1);
}

int	check_int(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		if (res > MAX_INT || res < MIN_INT)
			return (0);
	}
	res *= sign;
	if (res > MAX_INT || res < MIN_INT)
		return (0);
	return (1);
}

void	free_list(t_list *head)
{
	t_list	*temp;

	if (head)
	{
		temp = head->next;
		free(head);
		free_list(temp);
	}
}
