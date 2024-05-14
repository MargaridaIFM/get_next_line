/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:05:22 by mfrancis          #+#    #+#             */
/*   Updated: 2024/05/14 14:20:58 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_gnl(char *s)
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

char	*ft_strjoin_gnl(char *prefix, char *sufix)
{
	char	*str;
	int		total_len;
	int		i;
	int		j;

	total_len = ft_strlen_gnl(prefix) + ft_strlen_gnl(sufix) + 1;
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
	while (sufix && sufix[j] && sufix[j] != '\n')
		str[i++] = sufix[j++];
	if (sufix[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	free(prefix);
	return (str);
}

int	organize_buffer(char *buffer)
{
	int	flag_line;
	int	i;
	int	j;

	i = 0;
	j = 0;
	flag_line = 0;
	while (buffer[i])
	{
		if (flag_line)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			flag_line = 1;
		buffer[i++] = '\0';
	}
	return (flag_line);
}
