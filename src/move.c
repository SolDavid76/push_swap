/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:35:08 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/10 13:14:47 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_list **start, char c)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *start;
	tmp = lst->next;
	lst->next = lst->next->next;
	tmp->next = lst;
	*start = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	swap(t_list **a, t_list **b)
{
	swap_ab(a, '\0');
	swap_ab(b, '\0');
	write(1, "ss\n", 3);
}

void	push_ab(t_list **start_a, t_list **start_b, char c)
{
	t_list	*a;
	t_list	*b;

	a = *start_a;
	b = *start_b;
	if (c == 'a')
	{
		*start_b = b->next;
		b->next = a;
		*start_a = b;
		write(1, "pa\n", 3);
	}
	if (c == 'b')
	{
		*start_a = a->next;
		a->next = b;
		*start_b = a;
		write(1, "pb\n", 3);
	}
}

void	rotate_ab(t_list **start_a, t_list **start_b, char c)
{
	t_list	lst;

	
}
