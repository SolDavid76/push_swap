/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:35:08 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/09 14:13:26 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *lst, char c)
{
	int	tmp;

	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}