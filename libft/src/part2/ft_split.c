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

//#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int pointer_num(char const *s, char c)
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
	n += 2;
	return (n);
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
			return (i + 1);
		i++;
	}
	return (i + 1);
}

static void charcpy(char *d, char *s, int cn)
{
	int		i;

	i = 0;
	while (i < (cn - 1))
	{
		d[i] = s[i];
		i++;
	}
	d[cn] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;
	int n;
	char *sp;
	int cn;
	
	sp = (char*)s;
	n = pointer_num(s,c);
	i = 0;
	ret = (char**)malloc(sizeof(char*) * n);
	ret[n -1] = (char*)0;

	while (i < (n - 1))
	{
		cn = char_count(sp, c);
		ret[i] = malloc(sizeof(char) * cn);
		charcpy(ret[i], sp, cn);
		sp += cn;
		i++;
	}
	return (ret); 
}

int main()
{
    char months[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** tokens;

    printf("months=[%s]\n\n", months);

    tokens = ft_split(months, ',');
    if (tokens)
    {
        int i;
        for (i = 0; *(tokens + i); i++)
        {
            printf("month=[%s]\n", *(tokens + i));
            free(*(tokens + i));
        }
        printf("\n");
        free(tokens);
    }

    return 0;
}
