/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:54:38 by qrolland          #+#    #+#             */
/*   Updated: 2022/12/20 16:54:39 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tabsize(int *tab)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (tab[i])
	{
		len++;
		i++;
	}
	return (len);
}
