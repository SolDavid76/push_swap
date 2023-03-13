/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:18:18 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/13 17:34:01 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	short_sort_three(t_list **start_a, t_list **start_b)
{
	t_list	*a;
	t_list	*b;

	a = *start_a;
	b = *start_b;
	if (ft_lst_min == a)
		push(&a, &b, 'b');
	if (a->content < a->next->content)
		rotate(&a, &b, 'a');
	*start_a = a;
	*start_b = b;
	return (1);
}

int	short_sort(t_list **start_a, t_list **start_b)
{
	t_list	*a;
	// t_list	*b;

	a = *start_a;
	// b = *start_b;
	if (ft_lstsize(a) == 2)
	{
		*start_a = swap_ab(*start_a, 'a');
		return (1);
	}
	if (ft_lstsize(a) == 3)
		return (short_sort_three(start_a, start_b));
	return (0);
}