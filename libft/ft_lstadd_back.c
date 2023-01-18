/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:14:55 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/18 23:27:54 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (new)
	{
		if (*lst)
		{
			node = ft_lstlast(*lst);
			node->next = new;
		}
		else
			*lst = new;
	}
}

// #include <stdio.h>
// int main (void)
// {
// 	t_list *a;
// 	t_list *b;

// 	a = ft_lstnew("a");
// 	b = ft_lstnew("b");
// 	ft_lstadd_back(&a, b);
// 	printf("%s\n", a->content);
// 	printf("%s\n", (a->next)->content);
// }