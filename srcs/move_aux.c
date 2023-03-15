/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:17 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/14 17:01:11 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_list **start, char c)
{
	t_list	*lst;

	lst = *start;
	*start = lst->next;
	ft_lstlast(lst)->next = lst;
	lst->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rotate(t_list **start_a, t_list **start_b)
{
	rotate(start_a, '\0');
	rotate(start_b, '\0');
	write(1, "rr\n", 3);
}

void	rrotate_ab(t_list **start, char c)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *start;
	while (lst->next->next != NULL)
		lst = lst->next;
	tmp = lst->next;
	tmp->next = *start;
	*start = tmp;
	lst->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrotate(t_list **start_a, t_list **start_b)
{
	rrotate(start_a, '\0');
	rrotate(start_b, '\0');
	write(1, "rrr\n", 3);
}
