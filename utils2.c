/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:20:18 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/16 11:34:52 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_a(t_list **a, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(a, ft_lstnew(array[i]));
		i++;
	}
}
