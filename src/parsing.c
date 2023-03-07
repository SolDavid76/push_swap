/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:54:47 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/07 06:02:20 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_check_content(t_list *lst)
{
	t_list	*tmp;
	
	while (lst)
	{
		tmp = lst->next;
		if (lst->content < -2147483648 || 2147483647 < lst->content)
			return (write(1, "ERROR\n", 7), 1);
		while (tmp)
		{
			if (tmp->content == lst->content)
				return (write(1, "ERROR\n", 7), 1);
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
	while(tab[i])
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
	int		j;

	i = 0;
	if (av[0][0] == '\0')
		return (write(1, "ERROR\n", 7), NULL);
	while (av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if ((av[i][j] < '0' || '9' < av[i][j]) && (av[i][j] != ' '))
				return (write(1, "ERROR\n", 7), NULL);
			j++;
		}
		i++;
	}
	i = 0;
	str = NULL;
	while (av[i])
		str = ft_strjoin(str, av[i++]);
	tab = ft_split(str, ' ');
	if (!tab)
		return (write(1, "ERROR\n", 7), NULL);
	return (listing(tab));
}
