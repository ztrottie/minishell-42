/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liatoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:08:44 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/27 14:01:01 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_li_atoi(const char *str)
{
	long int	nb;
	int			sign;
	int			i;

	nb = 0;
	i = 0;
	sign = 1;
	if (str[i] && str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * sign);
}
