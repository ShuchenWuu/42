/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:09:46 by awu               #+#    #+#             */
/*   Updated: 2022/01/26 15:15:58 by awu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	is_neg(int n)
{
	if (n < 0)
		return (-1);
	if (n > 0)
		return (1);
	return (0);
}

static void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

static int	ft_bit(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		isneg;
	char	*ret;
	char	c;
	int		i;

	i = 0;
	isneg = is_neg(n);
	ret = malloc(sizeof(char) * ft_bit(n));
	if (!ret)
		return (NULL);
	if (n == 0)
		ret[0] = '0';
	while (n != 0)
	{
		ret[i++] = '0' + ft_abs(n % 10);
		n = n / 10;
	}
	if (isneg == -1)
		ret[i] = '-';
	ft_strrev(ret);
	return (ret);
}
/*
int main()
{
    int n;
    char *s;

    n = 0;
    s = ft_itoa(n);
    printf("%s\n", s);

}*/
