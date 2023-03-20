/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:57:00 by djanusz           #+#    #+#             */
/*   Updated: 2023/03/20 11:32:30 by djanusz          ###   ########.fr       */
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

char	*ft_calloc(int size)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
		res[i++] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!res)
		return (write(1, "NOT ENOUGH MEMORY\n", 18), free(s1), exit(1), NULL);
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

long int	ft_atol(char *str)
{
	long int	res;
	int			sign;
	int			i;

	i = 0;
	res = 0;
	sign = 1;
	if (!str)
		exit(write(2, "Error\n", 6));
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] < '0' || '9' < str[i + 1])
			return (2147483648);
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (sign * res);
}
