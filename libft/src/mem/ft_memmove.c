/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:00:37 by awu               #+#    #+#             */
/*   Updated: 2022/01/26 14:35:12 by awu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	len = len - 1;
	if (s < d)
	{
		while (len >= 0)
		{
			*(d + len) = *(s + len);
			len--;
		}
		return (dst);
	}
	while (len >= 0)
	{
		*d++ = *s++;
		len--;
	}
	printf("After memmove dest = %s\n", d);
	return (dst);
}

/*
int main () {
   char dest[] = "qqqqqqq";
   char src[]  = "abcd";
   

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   ft_memmove(dest, src, 8);
   //printf("After memmove dest = %s, src = %s\n", dest, src);

   char *a;
   char *b;


   a = "abcd";
   b = "qqqqqqqqq";
   if(a == b)
        printf("a = b\n");
    if(a > b)
        printf("a > b\n");
    if(a < b)
        printf("a < b\n");

   return(0);
}*/
