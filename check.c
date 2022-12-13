/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:23:40 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/11 21:12:33 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_split(char **splitted)
{
	int i = 0;

	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

int all_digits(char **argv)
{
	int i;
	int j;
	
	i = 1;
	while(argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i++])
		;
	return (i);
}

char	*ft_strdup(const char *s1)
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

char **copy_argv(char **argv)
{
	char **res;
	int i;
	int j;

	i = 0;
	while (argv[i++])
		;
	res = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (argv[++i])
		res[i - 1] = ft_strdup(argv[i]);
	return res;
}

char  **split_if_needed(int argc, char **argv)
{
	char **res;

	if (argc == 2 && !all_digits(argv))
	{
		res = ft_split(argv[1], ' ');
	}
	else
		res = copy_argv(argv);
	if (!all_digits(res))
	{
		free_split(res);
		return (NULL);
	}
	return (res);
}