/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:11:43 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/11 12:11:44 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa_check(t_stack **a, t_stack **b)
{
	if (!b || !*b)
		return ;
	push_front(a, (*b)->value, (*b)->index);
	pop_front(b);
}

void	pb_check(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	push_front(b, (*a)->value, (*a)->index);
	pop_front(a);
}
