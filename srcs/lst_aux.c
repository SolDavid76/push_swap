/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:09:59 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/14 14:24:36 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*ft_lst_max(t_list *lst)
{
	t_list	*res;

	res = lst;
	while (lst)
	{
		if (res->content < lst->content)
			res = lst;
		lst = lst->next;
	}
	return (res);
}

t_list	*ft_lst_min(t_list *lst)
{
	t_list	*res;

	res = lst;
	while (lst)
	{
		if (res->content > lst->content)
			res = lst;
		lst = lst->next;
	}
	return (res);
}

t_list	*ft_lst_median(t_list *lst)
{
	int	median;
	int	i;

	i = 0;
	median = ft_lstsize(lst) / 2;
	while (i++ < median)
		lst = lst->next;
	return (lst);
}

int	ft_lst_index(t_list *lst, t_list *elem)
{
	int	i;

	i = 0;
	while (lst != elem)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
