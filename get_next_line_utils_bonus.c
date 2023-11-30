/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:56:27 by ddemydov          #+#    #+#             */
/*   Updated: 2023/03/13 15:43:15 by ddemydov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen( const char *str )
{
	int	lenght;

	lenght = 0;
	while (str[lenght] != '\0')
	{
		lenght++;
	}
	return (lenght);
}

char	*ft_strrchr(const char *str, int to_find)
{
	char	*answer;
	int		count;

	if (str == 0)
	{
		return (0);
	}
	answer = (char *) str;
	count = ft_strlen(str);
	while (count >= 0)
	{
		if (answer[count] == (char )to_find)
		{
			return (&answer[count]);
		}
	count--;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*answer;
	size_t	indexs1;
	size_t	indexs2;

	answer = (char *)malloc(ft_strlen(s1)+ft_strlen(s2)+1);
	if (answer == NULL)
		return (NULL);
	indexs1 = 0;
	indexs2 = 0;
	while (s1[indexs1])
	{
	answer[indexs1] = s1[indexs1];
	indexs1++;
	}
	while (s2[indexs2])
	{
	answer[indexs1] = s2[indexs2];
	indexs1++;
	indexs2++;
	}
	answer[indexs1] = 0;
	return (answer);
}

char	*ft_substr(char const *s, unsigned int start, size_t end)
{
	char			*answer;
	size_t			aindex;
	size_t			count;

	aindex = 0;
	count = 0;
	if (end == 0)
		return (0);
	if (ft_strlen(s) < end)
		end = ft_strlen(s);
	answer = (char *)malloc(sizeof(char) * (end + 1));
	if (!answer)
		return (0);
	while (s[count])
	{
		if (count >= start && aindex < end)
		{
			answer[aindex] = s[count];
			aindex++;
		}
		count++;
	}
	answer[aindex] = '\0';
	return (answer);
}
