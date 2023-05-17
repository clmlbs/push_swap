/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:30:02 by cleblais          #+#    #+#             */
/*   Updated: 2022/12/08 14:39:19 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_3_nb(int *col_a, int *ia)
{
	if ((col_a[0] > col_a[2] && col_a[2] > col_a[1])
		|| (col_a[1] > col_a[0] && col_a[0] > col_a[2])
		|| (col_a[2] > col_a[1] && col_a[1] > col_a[0]))
		ps_mvts_sa(col_a, ia);
	if (col_a[2] > col_a[0] && col_a[0] > col_a[1])
		ps_mvts_ra(col_a, ia);
	if (col_a[1] > col_a[2] && col_a[2] > col_a[0])
		ps_mvts_rra(col_a, ia);
}

void	ps_4_nb_exp(int *col_a, int *ia)
{
	ps_mvts_sa(col_a, ia);
	ps_mvts_ra(col_a, ia);
	ps_mvts_ra(col_a, ia);
	ps_mvts_sa(col_a, ia);
}

void	ps_4_nb(int *col_a, int *ia, int *ib)
{
	int	col_b[2];

	if (col_a[3] > col_a[2])
		ps_mvts_sa(col_a, ia);
	while (col_a[3] > col_a[0])
		ps_mvts_rra(col_a, ia);
	ps_mvts_pb(col_a, col_b, ia, ib);
	ps_3_nb(col_a, ia);
	ps_mvts_pa(col_a, col_b, ia, ib);
	if (col_a[3] > col_a[0])
		ps_mvts_ra(col_a, ia);
	if (col_a[1] > col_a[3] && col_a[3] > col_a[2])
		ps_mvts_sa(col_a, ia);
	if (col_a[3] > col_a[1] && col_a[1] > col_a[2])
	{
		ps_mvts_rra(col_a, ia);
		ps_mvts_sa(col_a, ia);
		ps_mvts_ra(col_a, ia);
		ps_mvts_ra(col_a, ia);
	}
}

void	ps_5_nb(int *col_a, int *ia)
{
	if (col_a[4] > col_a[0])
		ps_mvts_ra(col_a, ia);
	if (col_a[2] > col_a[4] && col_a[4] > col_a[3])
		ps_mvts_sa(col_a, ia);
	if (col_a[4] > col_a[1] && col_a[1] > col_a[2] && col_a[2] > col_a[3])
	{
		ps_mvts_rra(col_a, ia);
		ps_mvts_sa(col_a, ia);
		ps_mvts_ra(col_a, ia);
		ps_mvts_ra(col_a, ia);
	}
	if (col_a[1] > col_a[4] && col_a[4] > col_a[2] && col_a[2] > col_a[3])
	{
		ps_mvts_sa(col_a, ia);
		ps_mvts_ra(col_a, ia);
		ps_mvts_sa(col_a, ia);
		ps_mvts_rra(col_a, ia);
	}
}

void	ps_medium_nb(int *col_a, int *ia, int *ib)
{
	int	col_b[2];
	int	ib_zero;

	ib_zero = -1;
	ps_mvts_pb(col_a, col_b, ia, ib);
	ps_4_nb(col_a, ia, &ib_zero);
	ps_mvts_pa(col_a, col_b, ia, ib);
	ps_5_nb(col_a, ia);
}
