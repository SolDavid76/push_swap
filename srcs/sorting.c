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

void	smart_push(t_list **start_a, t_list **start_b)
{
	t_list	*elem;
	int		move;
	t_list	*a;
	t_list	*b;

	a = *start_a;
	b = *start_b;
	elem = best_elem(a, b);
	move = estim_move(b, elem);
	if (move >= ft_lst_index(b, ft_lst_median(b)))
	{
		while (move != ft_lstsize(b))
		{
			if (estim_rrotate(b, elem))
				rrotate(&a, &b);
			else
				rrotate_ab(&b, 'b');
			move++;
		}
	}
	else
	{
		while (move != 0)
		{
			if (estim_rotate(b, elem))
				rotate(&a, &b);
			else
				rotate_ab(&b, 'b');
			move--;
		}
	}
	while (b)
		push_elem(&a, &b, b, 'a');
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
	while (b)
		push(&b, &a, 'a');
	*start_a = a;
	*start_b = b;
}
