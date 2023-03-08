/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:54:47 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/08 11:38:08 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tab_check_content(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '\0')
			return (write(1, "ERROR\n", 7), exit(1), 1);
		while (tab[i][j])
		{
			if ((tab[i][j] < '0' || '9' < tab[i][j]) && tab[i][j] != '+' && tab[i][j] != '-' && tab[i][j] != ' ')
				return (write(1, "ERROR\n", 7), exit(1), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_lst_check_content(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (tmp->content == lst->content)
				return (write(1, "ERROR\n", 7), exit(1), 1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

t_list	*listing(char **tab)
{
	t_list	*res;
	int		i;

	i = 0;
	res = ft_lstnew(ft_atol(tab[i++]));
	while (tab[i])
		ft_lstadd_back(&res, ft_lstnew(ft_atol(tab[i++])));
	if (ft_lst_check_content(res))
		return (ft_lst_free(res), free_tab(tab), NULL);
	return (free_tab(tab), res);
}

t_list	*parsing(char **av)
{
	char	**tab;
	char	*str;
	int		i;

	ft_tab_check_content(av);
	i = 0;
	str = NULL;
	while (av[i])
		str = ft_strjoin(str, av[i++]);
	tab = ft_split(str, ' ');
	if (!tab)
		return (write(1, "ERROR\n", 7), NULL);
	return (listing(tab));
}
