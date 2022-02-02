/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:40:04 by awu               #+#    #+#             */
/*   Updated: 2022/01/26 14:41:43 by awu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (0);
	ret = ft_memcpy(ret, s1, len);
	return (ret);
}
