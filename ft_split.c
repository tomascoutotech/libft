#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (s[1] == c || s[1] == '\0'))
			count++;
		s++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	*free_all(char **arr, size_t n)
{
	while (n > 0)
	{
		n--;
		free(arr[n]);
	}
	free(arr);
	return (NULL);
}

static char	**fill(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = word_len(s, c);
			arr[i] = ft_substr(s, 0, len);
			if (!arr[i])
				return (free_all(arr, i));
			i++;
			s += len;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	return (fill(arr, s, c));
}
