/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:00:16 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/23 18:00:18 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	extra_exec_functions(t_list **head_a, t_list **head_b, char *str)
{
	if (!ft_strncmp(str, "sa\0", 3))
		return (swap_first_two(head_a), 0);
	else if (!ft_strncmp(str, "sb\0", 3))
		return (swap_first_two(head_b), 0);
	else if (!ft_strncmp(str, "pa\0", 3))
		return (push_first_from_b_to_a(head_a, head_b), 0);
	else if (!ft_strncmp(str, "pb\0", 3))
		return (push_first_from_b_to_a(head_b, head_a), 0);
	else if (!ft_strncmp(str, "ss\0", 3))
	{
		swap_first_two(head_a);
		return (swap_first_two(head_b), 0);
	}
	return (1);
}

int	exec_instruction(t_list **head_a, t_list **head_b, char *str)
{
	if (!ft_strncmp(str, "ra\0", 3))
		return (rotate(head_a), 0);
	else if (!ft_strncmp(str, "rb\0", 3))
		return (rotate(head_b), 0);
	else if (!ft_strncmp(str, "rra\0", 4))
		return (rotate_reverse(head_a), 0);
	else if (!ft_strncmp(str, "rrb\0", 4))
		return (rotate_reverse(head_b), 0);
	else if (!ft_strncmp(str, "rrr\0", 4))
	{
		rotate_reverse(head_a);
		return (rotate_reverse(head_b), 0);
	}
	else if (!ft_strncmp(str, "rr\0", 3))
	{
		rotate(head_a);
		return (rotate(head_b), 0);
	}
	else
		return (extra_exec_functions(head_a, head_b, str));
}

int	read_instructions(t_list **head_a, t_list **head_b)
{
	char	*str;
	int		return_value;

	str = get_next_line(0);
	return_value = 0;
	while (str)
	{
		str[ft_strlen(str) - 1] = '\0';
		return_value = exec_instruction(head_a, head_b, str);
		free(str);
		if (return_value)
			return (1);
		str = get_next_line(0);
	}
	return (return_value);
}

int	finish(t_list *head_a, t_list *head_b, char **other_var, int return_value)
{
	if (head_a)
		free_list(head_a);
	if (head_b)
		free_list(head_b);
	if (other_var)
		free_split(other_var);
	return (return_value);
}

int	worker(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	char	**other_var;
	int		i;

	i = 0;
	if (argc < 2)
		return (1);
	other_var = split_if_needed(argc, argv);
	if (!other_var)
		return (2);
	head_a = new_list(ft_atoi(other_var[i++]));
	head_b = NULL;
	while (other_var[i])
		add_back(head_a, new_list(ft_atoi(other_var[i++])));
	if (!check_repetitions(head_a))
		return (finish(head_a, head_b, other_var, 2));
	if (read_instructions(&head_a, &head_b))
		return (finish(head_a, head_b, other_var, 2));
	if (check_if_stack_sorted(head_a) && i == list_len(head_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (finish(head_a, head_b, other_var, 0));
}
