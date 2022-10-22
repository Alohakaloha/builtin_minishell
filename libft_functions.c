#include "builtin.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	length;

	length = 0;
	if (length < size)
	{
		while (src[length] && length < (size - 1))
		{
			dst[length] = src[length];
			length++;
		}
	}
	if (size != '\0')
		dst[length] = '\0';
	while (src[length])
		length++;
	return (length);
}

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter.  The array must be
ended by a NULL pointer.*/
static char	**to_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || ft_strlen(s) <= start || !len)
		return (ft_strdup(""));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static int	ft_countword(char const *str, char c)
{
	int	i;
	int	nbr_words;

	i = 0;
	nbr_words = 1;
	while (str[i] != '\0')
	{
		if ((str[i] == c && str[i + 1] != c))
			nbr_words++;
		i++;
	}
	if (str[ft_strlen(str) - 1] == c)
		nbr_words--;
	if (str[0] == c)
		nbr_words--;
	return (nbr_words);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	ptr = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!ptr)
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			ptr[j] = ft_substr(s, i, ft_wordlen(&s[i], c));
			if (!ptr[j])
				return (to_free(ptr));
			i = i + ft_strlen(ptr[j]) - 1;
			j++;
		}
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	size;
	char	*p;
	char	*s;

	p = (char *)dest;
	s = (char *)src;
	size = 0;
	if (!dest && !src)
		return (NULL);
	while (size < n)
	{
		*p++ = *s++;
		size++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	i;

	if (!src)
		return (NULL);
	str = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
