/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:18:18 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/15 18:25:14 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	short_sort_three(t_list **start_a, t_list **start_b)
{
	t_list	*a;
	t_list	*b;

	a = *start_a;
	b = *start_b;
	if (a->content > a->next->next->content)
		rrotate_ab(&a, 'a');
	if (a->content > a->next->content && !ft_lst_is_sorted(a))
		swap_ab(&a, 'a');
	if (a->next->content > a->next->next->content && !ft_lst_is_sorted(a))
		rrotate_ab(&a, 'a');
	if (a->content > a->next->content && !ft_lst_is_sorted(a))
		swap_ab(&a, 'a');
	*start_a = a;
	*start_b = b;
	return (1);
}

int	short_sort_four(t_list **start_a, t_list **start_b)
{
	t_list	*a;
	t_list	*b;

	a = *start_a;
	b = *start_b;
	push_elem(&a, &b, ft_lst_min(a), 'a');
	short_sort_three(&a, &b);
	push(&b, &a, 'a');
	*start_a = a;
	*start_b = b;
	return (1);
}

int	short_sort_five(t_list **start_a, t_list **start_b)
{
	t_list	*a;
	t_list	*b;

	a = *start_a;
	b = *start_b;
	push_elem(&a, &b, ft_lst_min(a), 'a');
	short_sort_four(&a, &b);
	push(&b, &a, 'a');
	*start_a = a;
	*start_b = b;
	return (1);
}

int	short_sort(t_list **start_a, t_list **start_b)
{
	t_list	*a;

	a = *start_a;
	if (ft_lstsize(a) == 2)
	{
		swap_ab(start_a, 'a');
		return (1);
	}
	if (ft_lstsize(a) == 3)
		return (short_sort_three(start_a, start_b));
	if (ft_lstsize(a) == 4)
		return (short_sort_four(start_a, start_b));
	if (ft_lstsize(a) == 5)
		return (short_sort_five(start_a, start_b));
	return (0);
}
