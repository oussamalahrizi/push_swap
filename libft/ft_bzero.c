/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:03:07 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/10 21:40:46 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = 0;
		i++;
	}
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char *s = 0;
// 	// char str[4] = "ouss";
// 	// bzero(str, 3);
// 	// printf("their :%s\n",str);
// 	// printf("mine before :%s\n",s);
// 	ft_bzero(s, 3);
// 	printf("mine :%s\n", s);
// 	return (0);
// }