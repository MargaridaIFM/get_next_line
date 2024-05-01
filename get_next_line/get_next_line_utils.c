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
	//printf("indx: %d\n", idx);
	return (idx);
}

char	*ft_strjoin_GNL(char *prefix, char *sufix)
{
	char	*str;
	int		total_len;
	int		i;
	int		j;

	total_len = ft_strlen_GNL(prefix) + ft_strlen_GNL(sufix) + 1;
	//printf("Alfarroba\n");
	str = malloc(total_len * sizeof(char));
	//printf("Alfarroba 1\n");
	if (!str)
		return (NULL);
	//printf("Alfarroba 2\n");
	i = 0;
	while (prefix && prefix[i])
	{
		str[i] = prefix[i];
		i++;
	}
	//printf("str: %s\n", str);
	j = 0;
	//printf("Alfarroba 3\n");
	while (sufix[j])
	{
		str[i] = sufix[j];
		if (sufix[j] == '\n')
			{
				/* printf("Alfarroba 3\n");
				str[i] = '\n';
				i++; */
				break ;
			}
		j++;
		i++;
	}
	//printf("Alfarroba 4\n");
	str[i] = '\0';
	free(prefix);
	//printf("Alfarroba 5\n");
	return (str);
}
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}