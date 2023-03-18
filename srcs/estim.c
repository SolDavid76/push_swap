/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:18:37 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/16 19:43:59 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* donne le nombre de coup pour que l'element x soit le premier de la liste */
int	estim_rotate(t_list *lst, t_list *x)
{
	if (ft_lst_index(lst, x) <= ft_lst_index(lst, ft_lst_median(lst)))
		return (ft_lst_index(lst, x));
	return (0);
}

/* donne le nombre de coup pour que l'element x soit le premier de la liste */
int	estim_rrotate(t_list *lst, t_list *x)
{
	if (ft_lst_index(lst, x) > ft_lst_index(lst, ft_lst_median(lst)))
		return ((ft_lstsize(lst) - ft_lst_index(lst, x)));
	return (0);
}

/* donne le nombre de coup pour que x soit bien push dans lst(lst_b) */
int	estim_move(t_list *lst, t_list *x)
{
	// t_list	*start;
	int		res;

	// start = lst;
	if (x->content > ft_lst_max(lst)->content)
		return (ft_lst_index(lst, ft_lst_max(lst)));
	if (x->content < ft_lst_min(lst)->content)
		return (ft_lst_index(lst, ft_lst_max(lst)));
	if (ft_lstlast(lst)->content > x->content && x->content > lst->content)
		return (0);
	res = 1;
	while (lst->next)
	{
		if (lst->content > x->content && x->content > lst->next->content)
			return (res);
		lst = lst->next;
		res++;
	}
	return (res);
}

/* donne le nombre de coup total pour bien place x dans b depuis a */
int	best_move(t_list *lst_a, t_list *lst_b, t_list *x)
{
	int	res;

	res = estim_move(lst_b, x);
	if (res > ft_lst_index(lst_b, ft_lst_median(lst_b)))
		res = ft_lstsize(lst_b) - res;
	return (res + estim_rotate(lst_a, x) + estim_rrotate(lst_a, x));
}

/* donne le meilleur elem a push dans b */
t_list	*best_elem(t_list *lst_a, t_list *lst_b)
{
	t_list	*start;
	t_list	*res;

	res = lst_a;
	start = lst_a;
	while (lst_a)
	{
		if (best_move(start, lst_b, lst_a) < best_move(start, lst_b, res))
			res = lst_a;
		lst_a = lst_a->next;
	}
	return (res);
}
