/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mvts_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:37:03 by cleblais          #+#    #+#             */
/*   Updated: 2022/12/08 15:17:05 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_mvts_sa(int *col_A, int *ia)
{
	int	buf;

	buf = col_A[*ia];
	col_A[*ia] = col_A[*ia - 1];
	col_A[*ia - 1] = buf;
	ft_printf("sa\n");
}

void	ps_mvts_sb(int *col_B, int *ib)
{
	int	buf;

	buf = col_B[*ib];
	col_B[*ib] = col_B[*ib - 1];
	col_B[*ib - 1] = buf;
	ft_printf("sb\n");
}

void	ps_mvts_ss(int *col_A, int *col_B, int *ia, int *ib)
{
	int	buf;

	buf = col_A[*ia];
	col_A[*ia] = col_A[*ia - 1];
	col_A[*ia - 1] = buf;
	buf = col_B[*ib];
	col_B[*ib] = col_B[*ib - 1];
	col_B[*ib - 1] = buf;
	ft_printf("ss\n");
}
