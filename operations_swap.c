/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:53:19 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/15 19:54:13 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head)
{
	swap_first_two(head);
	write(1, "sa\n", 3);
}

void	sb(t_list **head)
{
	swap_first_two(head);
	write(1, "sb\n", 3);
}

void	ss(t_list **head_a, t_list **head_b)
{
	swap_first_two(head_b);
	swap_first_two(head_a);
	write(1, "ss\n", 3);
}
