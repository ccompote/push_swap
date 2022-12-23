/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:59:29 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/23 17:59:31 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	pc(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		pc(s[i]);
		i++;
	}
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*p;
	int		j;

	j = 0;
	i = ft_strlen(s1);
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	while (j < i)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

void	free_list(t_list *head)
{
	t_list	*temp;

	if (head)
	{
		temp = head->next;
		free(head);
		free_list(temp);
	}
}
