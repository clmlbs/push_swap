/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:16:52 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/17 08:57:12 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

typedef struct s_count
{
	unsigned int	count;
	unsigned int	j;
	unsigned int	start;
	size_t			len;
}	t_count;

static t_count	*ft_count_init(void)
{
	t_count	*nbr;

	nbr = (t_count *)malloc(sizeof(t_count));
	if (!nbr)
		return (NULL);
	nbr->count = 0;
	nbr->j = 0;
	nbr->start = 0;
	nbr->len = 0;
	return (nbr);
}

static void	ft_fillstrs(char const *s, char c, char **strs, t_count *n)
{
	unsigned int	i;

	i = 0;
	while (n->j < n->count)
	{
		while (s[i] == c)
			i++;
		n->start = i;
		while (s[i] != c && s[i])
			i++;
		n->len = i - n->start;
		strs[n->j] = ft_substr(s, n->start, n->len);
		if (!strs[n->j])
		{
			n->j--;
			while (n->j >= 0)
			{
				free(strs[n->j]);
				n->j--;
			}
			return ;
		}
		n->j++;
	}
	strs[n->j] = 0;
}

char	**ft_split(char const *s, char c)
{
	t_count	*n;
	char	**strs;
	int		i;

	if (!s)
		return (NULL);
	n = ft_count_init();
	if (!n)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n->count++;
		i++;
	}
	strs = (char **)malloc(sizeof(strs) * (n->count + 1));
	if (!strs)
	{
		free(n);
		return (NULL);
	}
	ft_fillstrs(s, c, strs, n);
	free(n);
	return (strs);
}
