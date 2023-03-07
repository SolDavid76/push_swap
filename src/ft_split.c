/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:43:36 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/07 06:12:03 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	nbr_word(char *str, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (i != 0 && str[i] == c && str[i - 1] != c)
			len++;
		i++;
	}
	if (i != 0 && str[i - 1] != c)
	len++;
	return (len);
}

char	*ft_split_aux(char *str, char c)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	j = 0;
	while (str[i] && str[i] != c)
		res[j++] = str[i++];
	res[j] = '\0';
	return (res);
}

char	**ft_split(char *str, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char *) * (nbr_word(str, c) + 1));
	if (!res)
		return (write(1, "NOT ENOUGH MEMORY\n", 19), free(str), NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		res[j] = ft_split_aux(str + i, c);
		if (!res[j++])
			return (free_tab(res), free(str), NULL);
		while (str[i] && str[i] != c)
			i++;
	}
	res[nbr_word(str, c)] = NULL;
	return (free(str), res);
}
