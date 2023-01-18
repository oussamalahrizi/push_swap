/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:10:44 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/19 04:12:32 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

// int main (void)
// {
// 	t_list *a = ft_lstnew("a");
// 	t_list *b = ft_lstnew("b");
// 	t_list *c = ft_lstnew("c");

// 	a->next = b;
// 	b->next = c;

// 	printf("%s\n", ft_lstlast(a)->content);
// }
