/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:22:53 by ccompote          #+#    #+#             */
/*   Updated: 2022/11/30 20:17:58 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	**temp;
	int	i;
	int len_a;
	int len_b;
	
	i = 1;
	if (argc < 2)
		return (0);
	head_a = new_list(ft_atoi(argv[i++]));
	while (i < argc)
		add_back(head_a, new_list(ft_atoi(argv[i++])));
	head_b = push_b(head_a);
	print_list(head_b);
	print_list(head_a);
	steps(head_a, head_b);
	print_list_steps(head_b);
	head_a = ra(head_a);
	
	temp = push_first_from_b_to_a(head_a, head_b);
	head_a = temp[0];
	head_b = temp[1];
	print_list(head_a);
	print_list(head_b);
	steps(head_a, head_b);
	print_list_steps(head_b);

	
/* 	while(head_a)
	{
		printf("%d\n", head_a->value);
		head_a = head_a->next;
	}
	printf("**\n");
	while(head_b)
	{
		printf("%d\n", head_b->value);
		head_b = head_b->next;
	} */
	return (0);
}