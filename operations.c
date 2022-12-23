/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:57:05 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/23 17:57:08 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **head)
{
	rotate(head);
	write(1, "ra\n", 3);
}

void	rra(t_list **head)
{
	rotate_reverse(head);
	write(1, "rra\n", 4);
}

void	rr(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
	write(1, "rr\n", 3);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	rotate_reverse(head_a);
	rotate_reverse(head_b);
	write(1, "rrr\n", 4);
}
