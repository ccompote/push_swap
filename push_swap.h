/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:09:47 by ccompote          #+#    #+#             */
/*   Updated: 2022/11/30 20:13:14 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int value;
	int steps;
	struct s_list *next;
}	t_list;

t_list	*push_b(t_list *head_a);
int	ft_atoi(const char *str);
void add_back(t_list *head, t_list *to_add);
t_list	*new_list(int value);
t_list	*swap_first_two(t_list *head);
t_list	*rotate(t_list *head);
t_list	*rotate_reverse(t_list *head);
t_list	*get_last(t_list *head);
char	*ft_itoa(int n);
void	ft_putstr(char *s);
int	list_len(t_list *head);
void print_list(t_list *head);
void print_list_steps(t_list *head);
void	steps(t_list *head_a, t_list *head_b);
void pc(int c);
t_list **push_first_from_b_to_a(t_list *head_a, t_list *head_b);


///////////////// operations
t_list *sa(t_list *head);
t_list *sb(t_list *head);
t_list **ss(t_list *head_a, t_list *head_b);
t_list *ra(t_list *head);
t_list *rb(t_list *head);
t_list *rra(t_list *head);
t_list *rrb(t_list *head);
t_list **rr(t_list *head_a, t_list *head_b);
t_list **rrr(t_list *head_a, t_list *head_b);

# endif