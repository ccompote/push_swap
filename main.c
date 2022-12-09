/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:22:53 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/09 17:29:04 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	huyanction(t_list **head)
// {
// 	t_list	*temp;
// 	t_list	*other_temp;
// 	other_temp = *head;
// 	temp = other_temp->next;
// 	if (!temp)
// 		return;
// 	other_temp->next = other_temp->next->next;
// 	temp->next = other_temp;
// 	print_list(temp);
// 	*head = temp;
// }


// int main(){
// 	t_list	*head_a;
// 	t_list	*head_b;

// 	head_a = new_list(1);
// 	head_b = NULL;
// 	head_a->next = new_list(2);
// 	head_a->next->next = new_list(3);
// 	print_list(head_a);
// 	push_first_from_b_to_a(&head_b, &head_a);
// 	push_first_from_b_to_a(&head_b, &head_a);

// 	print_list(head_a);
// 	print_list(head_b);
// }


int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	**temp;
	int		i;
	int 	len_a;
	int 	len_b;
	
	i = 1;
	if (argc < 2)
		return (0);
	head_a = new_list(ft_atoi(argv[i++]));
	while (i < argc)
		add_back(head_a, new_list(ft_atoi(argv[i++])));
	head_b = push_b(&head_a);
	print_list(head_b);
	print_list(head_a);
	/* steps(head_a, head_b);
	
	print_list_steps(head_b);
	// head_a = ra(	&head_a);
	
	push_first_from_b_to_a(&head_a, &head_b);
	print_list(head_a);
	print_list(head_b);
	steps(head_a, head_b);
	print_list_steps(head_b);
	sa(&head_a);
	print_list(head_a); */
	sort(&head_a, &head_b);
	print_list(head_b);
	print_list(head_a);

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
