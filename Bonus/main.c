/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:17:16 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/20 22:11:24 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	extra_exec_functions(t_list **head_a, t_list **head_b, char *str)
{
	if (!ft_strncmp(str, "sa", 2))
		swap_first_two(head_a);
	else if (!ft_strncmp(str, "sb", 2))
		swap_first_two(head_b);
	else if (!ft_strncmp(str, "pa", 2))
		push_first_from_b_to_a(head_a, head_b);
	else if (!ft_strncmp(str, "pb", 2))
		push_first_from_b_to_a(head_b, head_a);
	else if (!ft_strncmp(str, "ss", 2))
	{
		swap_first_two(head_a);
		swap_first_two(head_b);
	}
}

void	exec_instruction(t_list **head_a, t_list **head_b, char *str)
{
	if (!ft_strncmp(str, "ra", 2))
		rotate(head_a);
	else if (!ft_strncmp(str, "rb", 2))
		rotate(head_b);
	else if (!ft_strncmp(str, "rra", 3))
		rotate_reverse(head_a);
	else if (!ft_strncmp(str, "rrb", 3))
		rotate_reverse(head_b);
	else if (!ft_strncmp(str, "rr", 2))
	{
		rotate(head_a);
		rotate(head_b);
	}
	else if (!ft_strncmp(str, "rrr", 3))
	{
		rotate_reverse(head_a);
		rotate_reverse(head_b);
	}
	else
		extra_exec_functions(head_a, head_b, str);
}

void	read_instructions(t_list **head_a, t_list **head_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		exec_instruction(head_a, head_b, str);
		free(str);
		str = get_next_line(0);
	}
}

int	check_if_stack_sorted(t_list *head)
{
	long	i;

	i = MIN_INT - 1;
	while (head)
	{
		if (head->value < i)
			return (0);
		i = head->value;
		head = head->next;
	}
	return (1);
}

int	worker(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	char	**other_var;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	other_var = split_if_needed(argc, argv);
	head_a = new_list(ft_atoi(other_var[i++]));
	head_b = NULL;
	while (other_var[i])
		add_back(head_a, new_list(ft_atoi(other_var[i++])));
	read_instructions(&head_a, &head_b);
	if (check_if_stack_sorted(head_a) && i == list_len(head_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_list(head_a);
	free_list(head_b);
	free_split(other_var);
	return (0);
}

