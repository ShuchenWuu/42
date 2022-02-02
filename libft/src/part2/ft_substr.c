/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:58:38 by awu               #+#    #+#             */
/*   Updated: 2022/01/26 16:00:54 by awu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	j = 0;
	i = 0;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		while (j < len && i >= start)
		{
			ret[j] = s[i];
			j++;
		}
		i++;
	}
	ret[len] = '\0';
	return (ret);
}
