/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:57:00 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/08 11:26:37 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!res)
		return (write(1, "NOT ENOUGH MEMORY\n", 19), free(s1), exit(1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		res[j++] = s1[i++];
	i = 0;
	if (s1)
		res[j++] = ' ';
	while (s2 && s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	if (s1)
		free(s1);
	return (res);
}

int	ft_atol(char *str)
{
	long int	res;
	int			sign;
	int			i;

	i = 0;
	res = 0;
	sign = 1;
	if (!str)
		exit(write(1, "ERROR\n", 7));
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	if (INT_MIN < res || res < INT_MAX)
		return (sign * res);
	else
		return (write(1, "ERROR\n", 7), free(str), exit(1), 1);
}
