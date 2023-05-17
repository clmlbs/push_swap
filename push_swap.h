/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:38:20 by cleblais          #+#    #+#             */
/*   Updated: 2022/12/08 16:05:32 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int		push_swap(int argc, char **argv, int *tab);
int		ps_all_checks(int argc, char **argv, int *tab, int i);
int		ps_is_sign_alone(int argc, char **argv);
long	ps_atoi(char *str, int *ok);
void	ps_check_duplicate(int argc, int *tab, int *ok);
int		ps_check_sorted(int argc, int *tab);
void	push_swap_big(int argc, int *tab, int *ia, int *ib);
void	push_swap_little(int argc, int *tab, int *ia, int *ib);
void	ps_mvts_sa(int *col_a, int *ia);
void	ps_mvts_sb(int *col_b, int *ib);
void	ps_mvts_ss(int *col_a, int *col_b, int *ia, int *ib);
void	ps_mvts_pa(int *col_a, int *col_b, int *ia, int *ib);
void	ps_mvts_pb(int *col_a, int *col_b, int *ia, int *ib);
void	ps_mvts_ra(int *col_a, int *ia);
void	ps_mvts_rra(int *col_a, int *ia);
void	ps_3_nb(int *col_a, int *ia);
void	ps_4_nb_exp(int *col_a, int *ia);
void	ps_4_nb(int *col_a, int *ia, int *ib);
void	ps_5_nb(int *col_a, int *ia);
void	ps_medium_nb(int *col_a, int *ia, int *ib);
void	ps_nb_ordered(int *tab, int size);
void	ps_nb_renamed(int *tab, int *tab_cpy, int size);
void	ps_radix(int *col_a, int *ia, int *ib, int size);

#endif
