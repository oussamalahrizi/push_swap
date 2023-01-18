/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:33:12 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/16 11:34:31 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "libft.h"
#include <limits.h>

const char	*skip_spaces(const char *nptr, int *sign)
{
	size_t	i;

	i = 0;
	while (nptr[i] && (nptr[i] == 32 || nptr[i] == '\n' || nptr[i] == '\t'
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*sign = -1;
		i++;
	}
	return (nptr + i);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	size_t	i;
	long	result;

	result = 0;
	i = 0;
	sign = 1;
	nptr = skip_spaces(nptr, &sign);
	if (!nptr[i])
		p_error();
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			p_error();
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	if (((result * sign) > 2147483647) || ((result * sign) < -2147483648))
		p_error();
	return (result * sign);
}
