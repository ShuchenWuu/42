/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:28:04 by awu               #+#    #+#             */
/*   Updated: 2022/01/26 15:58:14 by awu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && inset(s1[start], set))
		start++;
	while (start < end && inset(s1[end - 1], set))
		end--;
	ret = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		ret[i] = s1[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
/*
int main () {
   char dest[] = "abcdefeheacde";
   char src[]  = "acde";
   char *ret;
   printf("Before trim dest = %s, src = %s\n", dest, src);
   ret = ft_strtrim(dest, src);
   printf("After trim ret = %s\n", ret);

   return(0);
}*/
