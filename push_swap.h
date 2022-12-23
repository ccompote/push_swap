/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:56:57 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/23 17:57:01 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_list
{
	int				value;
	int				steps;
	struct s_list	*next;
	int				cur_pos_b;
	int				cur_pos_a;
}	t_list;

t_list	*push_b(t_list **head_a);
int		ft_atoi(const char *str);
void	add_back(t_list *head, t_list *to_add);
t_list	*new_list(int value);
void	swap_first_two(t_list **head);
void	rotate(t_list **head);
void	rotate_reverse(t_list **head);
void	push_first_from_b_to_a(t_list **a, t_list **b);
t_list	*get_last(t_list *head);
char	*ft_itoa(int n);
void	ft_putstr(char *s);
int		list_len(t_list *head);
void	print_list(t_list *head);
void	print_list_steps(t_list *head);
void	steps(t_list *head_a, t_list *head_b);
void	pc(int c);
void	push_first_from_b_to_a(t_list **a, t_list **b);
void	sort(t_list **head_a, t_list **head_b);
int		find_median(t_list *head);
int		check_repetitions(t_list *head);
void	free_list(t_list *head);
void	add_front(t_list **head, t_list *to_add);
char	**ft_split(char const *s, char c);
char	**split_if_needed(int argc, char **argv);
void	free_split(char **splitted);
int		check_int(char *str);
void	sa(t_list **head);
void	sb(t_list **head);
void	ss(t_list **head_a, t_list **head_b);
void	ra(t_list **head);
void	rb(t_list **head);
void	rra(t_list **head);
void	rrb(t_list **head);
void	rr(t_list **head_a, t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);
void	pb(t_list **head_a, t_list **head_b);
void	pa(t_list **head_a, t_list **head_b);
int		finish(t_list *head_a, t_list *head_b,
			char **other_var, char *exit_message);
int		find_min_steps(t_list *b);
void	f1(t_list *b, t_list **head_a, t_list **head_b);
void	f2(t_list *b, t_list **head_a, t_list **head_b);
void	f3(t_list *a, t_list *b, t_list **head_a, t_list **head_b);
void	f4(t_list *b, t_list **head_a, t_list **head_b);
void	f5(t_list *a, t_list *b, t_list **head_a, t_list **head_b);
void	f6(t_list *b, t_list **head_a, t_list **head_b);
void	f7(t_list *b, t_list **head_a, t_list **head_b);
void	f8(t_list *a, t_list *b, t_list **head_a, t_list **head_b);
int		ll(int cur_pos_b, int cur_pos_a, t_list *head_b, t_list *temp);
void	oll(t_list *head_b, t_list *temp, int cur_pos_a, int cur_pos_b);
int		min(int a, int b);
int		max(int a, int b);
char	*ft_strdup(const char *s1);

#endif