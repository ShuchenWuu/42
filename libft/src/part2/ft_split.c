/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:18:45 by awu               #+#    #+#             */
/*   Updated: 2022/01/26 16:05:03 by awu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	**pointer_malloc(char const *s, char c)
{
	int		i;
	int		n;
	char	**ret;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			n++;
		i++;
	}
	n += 1;
	ret = malloc(sizeof(char *) * n);
	if (!ret)
		return (NULL);
	ret[n] = 0;
	return (ret);
}

static char	*char_malloc(char const *s, char c)
{
	char	*ret;
	int		n;

	n = ft_strlen(s);
	n = n + 1;
	ret = malloc(sizeof(char) * n);
	if (!ret)
		return (NULL);
	return (ret);
}

static int	char_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static char *charcpy(char const *s, char c)
{
	int		i;
	int 	n;
	char 	*ret;
	
	n = char_count(s, c);
	i = 0;
	while (i < n)
	{
		ret[i] = s[i];
		i++;
	}
	ret[n] = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		i;
    int		start;
	char	**ret;
	char	*str;
	int		len;
	
	i = 0;
	start = 0;
	len = ft_strlen(s);
	ret = pointer_malloc(s,c);
	if (!char_malloc(s,c) || !ret)
		return (NULL);
	while (ret[i])
	{
		if (start == 0)
			ret[i] = charcpy(&s[start], c);
		while (start < len)
		{
			start = char_count(&s[start], c);
			ret[i] = charcpy(&s[start], c);
		}
		i++;
	}
	return (ret); 
}
/*
int main()
{
    char months[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** tokens;

    printf("months=[%s]\n\n", months);

    tokens = ft_split(months, ',');
printf("1");
    if (tokens)
    {
        int i;
        for (i = 0; *(tokens + i); i++)
        {
            printf("1");
            printf("month=[%s]\n", *(tokens + i));
            free(*(tokens + i));
        }
        printf("\n");
        free(tokens);
    }

    return 0;
}*/
