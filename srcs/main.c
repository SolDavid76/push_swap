/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:41:28 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/14 17:04:30 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (ac == 1)
		return (1);
	lst_a = parsing(av + 1);
	lst_b = NULL;
	if (!lst_a)
		return (1);
	ft_sorting(&lst_a, &lst_b);
	ft_lst_free(lst_a);
	ft_lst_free(lst_b);
}
