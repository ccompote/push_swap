/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:59:34 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/23 17:59:35 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_atoi(const char *str)
{
	long int	res;
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
	}
	return (res * sign);
}

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

int	check_if_stack_sorted(t_list *head)
{
	long	i;

	i = MIN_INT - 1;
	while (head)
	{
		if (head->value <= i)
			return (0);
		i = head->value;
		head = head->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = worker(argc, argv);
	if (i == 2)
		ft_putstr("Error\n");
	return (0);
}
