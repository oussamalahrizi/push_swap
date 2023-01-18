/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:06:59 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/20 04:35:34 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*result;

	if (nelem && elsize > SIZE_MAX / nelem)
		return (0);
	result = malloc(nelem * elsize);
	if (!result)
		return (0);
	ft_bzero(result, nelem * elsize);
	return (result);
}

// #include <stdio.h>

// int main (void)
// {
// 	if (ft_calloc(SIZE_MAX, SIZE_MAX))
// 		printf("1");
// 	else
// 		printf("0");
// 	return (0);
// }