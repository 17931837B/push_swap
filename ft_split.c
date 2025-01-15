/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:19:38 by tobaba            #+#    #+#             */
/*   Updated: 2024/04/17 14:19:38 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	check_sep(char c, char sep)
{
	return (c == sep);
}

static int	count_word(const char *str, char sep)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != sep && !in_word)
		{
			words++;
			in_word = 1;
		}
		else if (*str == sep)
		{
			in_word = 0;
		}
		str++;
	}
	return (words);
}

static char	*copy_word(const char *top, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = top[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *str, char sep)
{
	int			words;
	int			i;
	char		**split;
	const char	*top;

	if (!str)
		return (NULL);
	words = count_word(str, sep);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*str && check_sep(*str, sep))
			str++;
		top = str;
		while (*str && !check_sep(*str, sep))
			str++;
		if (str > top)
			split[i] = copy_word(top, str - top);
		i++;
	}
	split[i] = NULL;
	return (split);
}
