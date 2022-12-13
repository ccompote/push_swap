/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:22:53 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/11 21:14:12 by ccompote         ###   ########.fr       */
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

int finish(t_list *head_a, t_list *head_b, char *exit_message)
{
	free_list(head_a);
	free_list(head_b);
	ft_putstr(exit_message);
	return (0);
}

int	sssort(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		i;
	int 	len_a;
	int 	len_b;
	char **other_var;
	
	i = 0;
	other_var = split_if_needed(argc, argv);
	if (argc < 2)
		return (0);
	head_a = new_list(ft_atoi(other_var[i++]));
	head_b = NULL;
	if (!head_a)
		return (finish(head_a, head_b, "Nothing given or malloc failed\n"));
	while (other_var[i])
		add_front(&head_a, new_list(ft_atoi(other_var[i++])));
	if (check_repetitions(head_a) == 0)
		return (finish(head_a, head_b, "input is incorrect or malloc failed\n"));
	head_b = push_b(&head_a);
	if (!head_b && head_a->steps == -1)
		return (finish(head_a, head_b, "Malloc failed\n"));
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
	free_split(other_var);
	return finish(head_a, head_b, "everything is good\n");
}

int main(int argc, char **argv)
{
	sssort(argc, argv);
	// system("leaks a.out");
}