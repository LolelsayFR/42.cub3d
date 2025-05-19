/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:23:01 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/20 00:03:01 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static int	max_len(t_list *lst)
{
	int	len;
	int	save;

	save = 0;
	while (lst != NULL)
	{
		len = ft_strlen(lst->content);
		if (len > save)
			save = len;
		lst = lst->next;
	}
	return (save);
}

char	**lst_to_map(t_list *lst)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_calloc(max_len(lst) + 1, sizeof(char *));
	while (lst != NULL)
	{
		tab[i++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}

char	**lst_to_tab(t_list *lst)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_calloc(max_len(lst) + 1, sizeof(char *));
	while (lst != NULL)
	{
		tab[i++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}
