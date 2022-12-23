/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:57:44 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/23 17:57:46 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	finish(t_list *head_a, t_list *head_b, char **other_var, char *exit_message)
{
	free_list(head_a);
	free_list(head_b);
	ft_putstr(exit_message);
	free_split(other_var);
	return (0);
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

int	sssort(int argc, char **argv, int i)
{
	t_list	*head_a;
	t_list	*head_b;
	char	**other_var;

	if (argc < 2)
		return (0);
	other_var = split_if_needed(argc, argv);
	if (!other_var)
		return (finish(NULL, NULL, NULL, "Error\n"));
	head_a = new_list(ft_atoi(other_var[i++]));
	head_b = NULL;
	if (!head_a)
		return (finish(head_a, head_b, other_var, "Error\n"));
	while (other_var[i])
		add_back(head_a, new_list(ft_atoi(other_var[i++])));
	if (check_if_stack_sorted(head_a))
		return (finish(head_a, NULL, other_var, ""));
	if (check_repetitions(head_a) == 0)
		return (finish(head_a, head_b, other_var, "Error\n"));
	head_b = push_b(&head_a);
	if (head_a->steps == -1)
		return (finish(head_a, head_b, other_var, "Error\n"));
	sort(&head_a, &head_b);
	return (finish(head_a, head_b, other_var, ""));
}

int	main(int argc, char **argv)
{
	sssort(argc, argv, 0);
}
