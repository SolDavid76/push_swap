/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:05:16 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/13 17:36:40 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_elem(t_list **start_a, t_list **start_b, t_list *elem)
// {
// 	int	median;

// 	median = ft_lst_median()
// }

int	ft_estimate(t_list *lst, t_list *elem)
{
	int	i;
	
	while (lst != elem)
	{
		lst = lst->next;
		i++;
	}
}

void	ft_sorting(t_list **start_a, t_list **start_b)
{
	t_list	*a;
	

	a = *start_a;
	if (ft_lst_is_sorted(a) || short_sort(start_a , start_b))
		return ;
	
}