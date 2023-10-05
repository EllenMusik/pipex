/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:19:34 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/09 17:55:02 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**mallocing(char **str, int position, int wordcount, int wordlen)
{
	if (position == 0)
		str = malloc(sizeof(char *) * (wordcount + 1));
	if (!str)
		return (0);
	str[position] = malloc(sizeof(char) * (wordlen + 1));
	if (!str[position])
	{
		while (position >= 0)
		{
			free(str[position]);
			position--;
		}
		free(str);
		return (0);
	}
	return (str);
}

static char	**counterformalloc(char const *s, char c, int wordcount)
{
	char	**splitm;
	int		i;
	int		position;
	int		wordlength;

	i = 0;
	position = 0;
	wordlength = 0;
	while (wordcount > 0)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			wordlength++;
		}
		splitm = mallocing(splitm, position, wordcount, wordlength);
		if (!splitm)
			return (0);
		wordlength = 0;
		position++;
		wordcount--;
	}
	return (splitm);
}

static int	wordcounter(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			wordcount++;
			while (s[i] == c)
				i++;
		}
		if (s[i])
			i++;
	}
	if (i != 0 && s[i - 1] != c)
		wordcount++;
	return (wordcount);
}

static int	fillinfunktion(char **split, char const *s, char c, int wordcount)
{
	int	i;
	int	l;
	int	m;

	i = 0;
	l = 0;
	m = 0;
	while (wordcount > 0)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			split[m][l] = s[i];
			l++;
			i++;
		}
		split[m][l] = '\0';
		l = 0;
		m++;
		wordcount--;
	}
	split[m] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**splittedstr;

	if (s == NULL || s[0] == '\0')
		wordcount = 0;
	else
		wordcount = wordcounter(s, c);
	if (wordcount > 0)
	{
		splittedstr = counterformalloc(s, c, wordcount);
		if (!splittedstr)
			return (0);
	}
	else
	{
		splittedstr = malloc(sizeof(char *) * 1);
		if (!splittedstr)
			return (NULL);
		splittedstr[0] = NULL;
	}
	if (wordcount > 0)
		fillinfunktion(splittedstr, s, c, wordcount);
	return (splittedstr);
}

/*
#include<stdio.h>

int main(void)
{
	char	**str_tab;
	char sep;

	str_tab = ft_split(str_tab, 0);
	printf("%s", str_tab);
	free(str_tab);

}
*/