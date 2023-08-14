/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:19:28 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:19:29 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/env.h"

int	is_valid_var(int c)
{
	if (ft_isalnum(c) || c == '_')
		return (VALID);
	return (INVALID);
}
