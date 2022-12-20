/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fuctions_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:49:01 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/20 22:10:56 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
