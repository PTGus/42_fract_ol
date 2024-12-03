/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:19:41 by gumendes          #+#    #+#             */
/*   Updated: 2024/10/31 11:09:29 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** @brief Counts the words of the string
 * 	@param s  string
 * 	@param c  separator
 *  @return Returns the number of words in the string
*/
static int	word_count(const char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

/** @brief Frees all the unused memory in the array of words
 * and the array itself.
 * 	@param strs  array of words
*/
static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static char	**split_words(char **result, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		s_word;

	i = 0;
	j = 0;
	s_word = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			result[j] = fill_word(s, s_word, i);
			if (!(result[j]))
				return (ft_free(result, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (result);
}

/** @brief Splits a string into an array of words
 * 	@param s  string
 * 	@param c  separator
 *  @return Returns an array of words
*/
char	**ft_split(const char *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	result = split_words(result, s, c);
	return (result);
}

/* int main(void)
{
	const char *str = "Hello, world! This is a test.";
	char delimiter = 'T';
	char **resultult;
	int i;

	resultult = ft_split(str, delimiter);
	if (!resultult)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}
	printf("Original string: \"%s\"\n", str);
	printf("Split resultult:\n");
	i = 0;
	while (resultult[i] != NULL)
	{
		printf("Word %d: \"%s\"\n", i + 1, resultult[i]);
		free(resultult[i]);
		i++;
	}
	free(resultult);
	return (0);
} */