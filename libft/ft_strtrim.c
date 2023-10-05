/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   ft_strtrim.c	   :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: esteiner <esteiner@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/01/12 12:29:36 by esteiner	  #+#	#+#	 */
/*   Updated: 2023/01/12 17:16:33 by esteiner	 ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkfront(char const *s1, char const *set, int k)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1[k] == set[i])
		{
			k++;
			return (ft_checkfront(s1, set, k));
		}
		i++;
	}
	return (k);
}

static int	ft_checkback(char const *s1, char const *set, int k)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1[k] == set[i])
		{
			k--;
			return (ft_checkback(s1, set, k));
		}
		i++;
	}
	k = ft_strlen(s1) - k;
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	int		k;

	k = 0;
	if (s1[k] == 0)
	{
		s2 = ft_substr(s1, 1, 1);
		return (s2);
	}
	i = ft_checkfront(s1, set, 0);
	if (i < ft_strlen(s1) - 1)
		k = ft_checkback(s1, set, ft_strlen(s1) - 1);
	s2 = ft_substr(s1, i, ft_strlen(s1) - i - k + 1);
	if (!s2)
		return (NULL);
	return (s2);
}

/*
int	main(void)
{
	printf("test: %s\n", ft_strtrim("I really love cats", "I reats"));
	return (0);
}
*/
