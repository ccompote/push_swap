/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:22:53 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/20 19:31:05 by ccompote         ###   ########.fr       */
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

int	sssort(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		i;
	char	**other_var;

	i = 0;
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
	sssort(argc, argv);
}
