/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:12:59 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/15 00:54:24 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	s_len;
	int		i;

	s_len = ft_strlen(s);
	dest = (char *) malloc((s_len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main ()
// {
// 	printf("%s", ft_strdup(NULL));
// 	return (0);
// }