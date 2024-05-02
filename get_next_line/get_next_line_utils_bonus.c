#include "get_next_line.h"

int	ft_strlen_GNL(char *s)
{
	int	idx;

	idx = 0;
	if (!s)
		return (0);
	while (s[idx] && s[idx] != '\n')
		idx++;
	if (s[idx] == '\n')
		idx++;
	return (idx);
}

char	*ft_strjoin_GNL(char *prefix, char *sufix)
{
	char	*str;
	int		total_len;
	int		i;
	int		j;

	total_len = ft_strlen_GNL(prefix) + ft_strlen_GNL(sufix) + 1;
	str = malloc(total_len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (prefix && prefix[i])
	{
		str[i] = prefix[i];
		i++;
	}
	j = 0;
	while (sufix && sufix[j] && sufix[j] != '\n' )
		str[i++] = sufix[j++];
	if (sufix[j] == '\n')
		str[i++] = '\n'; 
	str[i] = '\0';
	free(prefix);
	return (str);
}

int organize_buffer(char  *buffer)
{
	int flag_line;
	int i;
	int j;

	i = 0;
	j = 0;
	flag_line = 0;

	while(buffer[i])
	{
		if(flag_line)
			buffer[j++] = buffer[i];
		if(buffer[i] == '\n')
			flag_line = 1;
		buffer[i++] = '\0';
	}
	return(flag_line);
}