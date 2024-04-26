#include "get_next_line.h"

int	ft_strlen_GNL(char *s)
{
	int	idx;

	idx = 0;
	if(!s)
		return(0);
	while (s[idx] && s[idx] != '\n')
		idx++;
	if(s[idx] == '\n')
		idx++;
	return (idx);
}

char *ft_strjoin_GNL(char *prefix, char *sufix)
{
	char	*str;
	int 	total_len;
	int		i;
	int 	j;

	total_len = ft_strlen_GNL(prefix) + ft_strlen_GNL(sufix) + 1;
	str = malloc(total_len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while(prefix && prefix[i])
	{  
		str[i] = prefix[i];
		i++;
	}
	j = 0;
	while(sufix[j])
	{ 
		str[i] = sufix[j];
		if (sufix[j] == '\n')
			break;		
		j++;
		i++; 
	}
	str[i] = '\n';
	return (str);
}

/*
char *ft_strjoin_GNL(char *prefix, char *sufix)
{
	char	*str;
	int 	total_len;
	int		i;
	int 	j;

	if (!prefix || !sufix)
		return (NULL);
	total_len = ft_strlen_GNL(prefix) + ft_strlen_GNL(sufix) + 1;
	str = malloc(total_len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while(prefix[i])
	{
		prefix[i] = str[i];
		i++;
	}
	j = 0;
	while(sufix[j] && sufix[j++] != '\n')
	{
		sufix[j] = str[i];
		j++;
		i++; 
	}
	str[i] = '\n';
	return (str);
}
size_t	ft_strlcpy(char *dst, const char *src)
{
	size_t	idx;

	idx = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size != 0)
	{
		while (idx < size - 1 && src[idx])
		{
			dst[idx] = src[idx];
			idx++;
		}
	}
	dst[idx] = '\0';
	return (ft_strlen(src));
}
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	if (size <= i)
		return (size + ft_strlen(src));
	j = 0;
	while (src[j] && size > i + 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}*/