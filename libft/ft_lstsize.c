/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:14:30 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/19 05:22:49 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

// int main ()
// {
// 	t_list *a;
// 	t_list *b;
// 	t_list *c;
// 	a = ft_lstnew((void *)"a");
// 	b = ft_lstnew((void *)"b");
// 	c = ft_lstnew((void *)"c");
// 	a->next = b;
// 	b->next = c;
// 	printf("%d\n", ft_lstsize(a));
// }