/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:40:30 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/08 18:26:01 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void		str_delete(t_string *str)
{
	if (str->alloc > 0)
		ft_strdel(&str->s);
	str->len = 0;
	str->alloc = 0;
}
