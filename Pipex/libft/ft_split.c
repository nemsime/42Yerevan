/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtumanya <mtumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:25:39 by mtumanya          #+#    #+#             */
/*   Updated: 2025/07/04 13:43:51 by mtumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	kvota(const char **s)
{
	const char	*tmp;

	if (**s == '\'')
	{
		tmp = ++(*s);
		while (*tmp != '\'' && *tmp)
			tmp++;
		if (*tmp == '\'')
			*s = tmp;
	}
	else
		(*s)++;
}

static int	word_count(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
			kvota(&s);
		}
		else
		{
			if (*s == c)
				in_word = 0;
			s++;
		}
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	if (s[start] == '\'' && s[end - 1] == '\'')
	{
		start++;
		end--;
	}
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_func(char const **s, int *start, int *end, char *c)
{
	while ((*s)[*end] == *c)
		(*end)++;
	*(start) = *(end);
	while ((*s)[(*end)] && (*s)[(*end)] != *c)
	{
		if ((*s)[(*end)] == '\'')
		{
			(*end)++;
			while ((*s)[(*end)] != '\'' && (*s)[(*end)])
				(*end)++;
			if ((*s)[(*end)] == '\'')
				(*end)++;
		}
		else
			(*end)++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		start;
	int		end;
	int		index;

	result = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !result)
		return (NULL);
	index = 0;
	end = 0;
	while (s[end])
	{
		ft_func(&s, &start, &end, &c);
		if (start < end)
		{
			result[index] = word_dup(s, start, end);
			if (!result[index])
			{
				free_all(result, index - 1);
				return (NULL);
			}
			index++;
		}
	}
	return (result[index] = NULL, result);
}
