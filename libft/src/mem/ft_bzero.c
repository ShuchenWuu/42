/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:58:58 by awu               #+#    #+#             */
/*   Updated: 2022/01/26 14:33:50 by awu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ret;

	ret = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ret[i] = '\0';
		i++;
	}
	s = ret;
}
