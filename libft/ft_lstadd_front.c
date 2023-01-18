/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 03:51:39 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/18 03:29:17 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		if (*lst)
			new->next = *lst;
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
// 	ft_lstadd_front(&a, b);
// 	// printf("%s\n", b->content);
// 	// printf("%s\n", (b->next)->content);
// 	while (a)
// 	{
// 		printf("%s\n", a->content);
// 		a = a->next;
// 	}
// }