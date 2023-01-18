/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 02:43:34 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/13 23:14:04 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		ft_putchar_fd(0, fd);
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

//#include <fcntl.h>
// int main (void)
// {
// 	int	fd = open("./file", O_WRONLY, 2);
// 	ft_putstr_fd("oussama", fd);
// 	close(fd);
// 	return (0);
// }