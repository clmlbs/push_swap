/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:37:00 by cleblais          #+#    #+#             */
/*   Updated: 2022/12/16 09:54:50 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_little(int argc, int *tab, int *ia, int *ib)
{
	if (argc == 4)
		ps_3_nb(tab, ia);
	if (argc == 5)
	{
		if (tab[3] > tab[2] && tab[2] > tab[1] && tab[1] > tab[0])
			ps_4_nb_exp(tab, ia);
		else
			ps_4_nb(tab, ia, ib);
	}
}

void	push_swap_big(int argc, int *tab, int *ia, int *ib)
{
	int	*tab_cpy;

	tab_cpy = (int *)malloc(sizeof(int) * argc - 1);
	if (!tab_cpy)
		return ;
	if (argc == 6)
	{
		ps_medium_nb(tab, ia, ib);
		free(tab_cpy);
	}
	if (argc > 6)
	{
		ft_memcpy(tab_cpy, tab, sizeof(int) * (argc - 1));
		ps_nb_ordered(tab_cpy, argc - 1);
		ps_nb_renamed(tab, tab_cpy, argc - 1);
		free(tab_cpy);
		ps_radix(tab, ia, ib, argc - 1);
	}
}

int	push_swap(int argc, char **argv, int *tab)
{
	int	ia;
	int	ib;

	ia = argc - 2;
	ib = -1;
	if (!ps_is_sign_alone(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!ps_all_checks(argc, argv, tab, ib))
		return (0);
	if (argc == 3)
		ft_printf("sa\n");
	if (argc == 4 || argc == 5)
		push_swap_little(argc, tab, &ia, &ib);
	if (argc >= 6)
		push_swap_big(argc, tab, &ia, &ib);
	return (0);
}

int	main(int argc, char **argv)
{
	int	*tab;

	tab = (int *)malloc(sizeof(int) * argc - 1);
	if (!tab)
		return (0);
	push_swap(argc, argv, tab);
	if (tab)
		free(tab);
	return (0);
}
