/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:56:02 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/15 19:56:29 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **head)
{
	rotate(head);
	write(1, "rb\n", 3);
}

void	rrb(t_list **head)
{
	rotate_reverse(head);
	write(1, "rrb\n", 4);
}
