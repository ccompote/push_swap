/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:23:40 by ccompote          #+#    #+#             */
/*   Updated: 2022/12/20 19:30:32 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	if (!splitted)
		return ;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

int	all_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**copy_argv(char **argv)
{
	char	**res;
	int		i;

	i = 0;
	while (argv[i++])
		;
	res = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (argv[++i])
		res[i - 1] = ft_strdup(argv[i]);
	return (res);
}

int	all_ints(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_int(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**split_if_needed(int argc, char **argv)
{
	char	**res;

	if (argc == 2 && !all_digits(argv))
	{
		res = ft_split(argv[1], ' ');
	}
	else
		res = copy_argv(argv);
	if (!all_digits(res) || !all_ints(res))
	{
		free_split(res);
		return (NULL);
	}
	return (res);
}
