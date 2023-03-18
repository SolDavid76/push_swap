/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:05:16 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/14 17:31:58 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_elem(t_list **start_src, t_list **start_dst, t_list *elem, char c)
{
	t_list	*src;
	t_list	*dst;

	src = *start_src;
	dst = *start_dst;
	while (src != elem)	
	{
		if (ft_lst_index(src, ft_lst_median(src)) < ft_lst_index(src, elem))
			rrotate_ab(&src, c);
		else
			rotate_ab(&src, c);
	}
	if (c == 'a')
		push(&src, &dst, 'b');
	if (c == 'b')
		push(&src, &dst, 'a');
	*start_src = src;
	*start_dst = dst;
}

void	smart_push(t_list **start_a, t_list **start_b)
{
	t_list	*elem;
	t_list	*a;
	t_list	*b;

	a = *start_a;
	b = *start_b;
	elem = best_elem(a, b);
	while (estim_move(b, elem))
	{
		if (estim_move(b, elem) >= ft_lst_index(b, ft_lst_median(b)))
		{
			if (estim_rrotate(a, elem))
				rrotate(&a, &b);
			else
				rrotate_ab(&b, 'b');
		}
		else
		{
			if (estim_rotate(a, elem))
				rotate(&a, &b);
			else
				rotate_ab(&b, 'b');
		}
	}
	push_elem(&a, &b, elem, 'a');
	*start_a = a;
	*start_b = b;
}

void	ft_sorting(t_list **start_a, t_list **start_b)
{
	t_list	*a;
	t_list	*b;

	a = *start_a;
	b = *start_b;
	if (ft_lst_is_sorted(a) || short_sort(start_a, start_b))
		return ;
	push(&a, &b, 'b');
	push(&a, &b, 'b');
	while (a)
		smart_push(&a, &b);
	while (b != ft_lst_max(b))
	{
		if (ft_lst_index(b, ft_lst_median(b)) < ft_lst_index(b, ft_lst_max(b)))
			rrotate_ab(&b, 'b');
		else
			rotate_ab(&b, 'b');
	}
	while (b)
		push(&b, &a, 'a');
	*start_a = a;
	*start_b = b;
}
