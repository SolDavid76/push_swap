/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:18:37 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/16 12:23:25 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	estim_rotate(t_list *lst, t_list *x)
{
	if (ft_lst_index(lst, x) <= ft_lst_index(lst, ft_lst_median(lst)))
		return (ft_lst_index(lst, x));
	return (0);
}

int	estim_rrotate(t_list *lst, t_list *x)
{
	if (ft_lst_index(lst, x) > ft_lst_index(lst, ft_lst_median(lst)))
		return ((ft_lstsize(lst) - ft_lst_index(lst, x)));
	return (0);
}

int	estim_move(t_list *lst, t_list *x)
{
	int	res;

	if (ft_lstlast(lst)->content > x->content && x->content > lst->content)
		return (0);
	res = 1;
	while (lst)
	{
		if (lst->content > x->content && x->content > lst->next->content)
			return (res);
		lst = lst->next;
		res++;
	}
	return (res);
}
// if (res >= ft_lst_index(lst, ft_lst_median(lst)))
//  res = ft_lstsize(lst) - res;
// it is sus

int	best_move(t_list *lst_a, t_list *lst_b, t_list *x)
{
	int	res;

	res = estim_move(lst_b, x);
	if (res >= ft_lst_index(lst_b, ft_lst_median(lst_b)))
		res = ft_lstsize(lst_b) - res;
	return (res + estim_rotate(lst_a, x) + estim_rrotate(lst_a, x));
}

t_list	*best_elem(t_list *lst_a, t_list *lst_b)
{
	t_list	*res;

	res = lst_a;
	while (lst_a)
	{
		if (best_move(lst_a, lst_b, res) > best_move(lst_a, lst_b, lst_a))
			res = lst_a;
		lst_a = lst_a->next;
	}
	return (res);
}
