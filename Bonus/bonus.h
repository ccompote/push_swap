/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:18:17 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/20 22:12:30 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
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

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_dup(char *str);
char	*ft_read(int fd, char *progress);
char	*ft_next_line(char *progress);
char	**split_if_needed(int argc, char **argv);
void	add_back(t_list *head, t_list *to_add);
void	print_list(t_list *head);
char	*ft_strdup(char *s1);
int		check_int(char *str);
char	**ft_split(char const *s, char c);
t_list	*get_last(t_list *head);
char	*ft_itoa(int n);
void	ft_putstr(char *s);
void	pc(int c);
int		list_len(t_list *head);
t_list	*new_list(int value);
int		ft_atoi(const char *str);
void	swap_first_two(t_list **head);
void	rotate(t_list **head);
void	rotate_reverse(t_list **head);
void	push_first_from_b_to_a(t_list **a, t_list **b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_list(t_list *head);
void	free_split(char **splitted);
int	worker(int argc, char **argv);
int	check_if_stack_sorted(t_list *head);
void	read_instructions(t_list **head_a, t_list **head_b);
void	exec_instruction(t_list **head_a, t_list **head_b, char *str);
void	extra_exec_functions(t_list **head_a, t_list **head_b, char *str);

#endif
