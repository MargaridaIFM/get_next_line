#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char		buffer[BUFFER_SIZE + 1];
	int			flag_read;
	
	//int i = 0;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		// printf("Buffer size or fd invalid");
		return (NULL);
	line = NULL;
	printf("line antes: %s\n", line);
	printf("Storage antes: %s\n", buffer);
	flag_read = 1;
	while (flag_read > 0)
	{
		flag_read = read(fd, buffer, BUFFER_SIZE);
		if (flag_read == -1)
		{
			free(line);
			return(NULL);
		}
		else if(flag_read == 0)
			break;
		buffer[flag_read] = '\0';
		line = ft_strjoin_GNL(line, buffer);
		buffer = clean_buffer(buffer);

		//printf("line %d depois: %s\n", i, line);
		//printf("Storage %d depois: %s\n", i ,buffer);
		//i++;
		
	}
	return(line);
}

char *clean_buffer(char *buffer)
{
    int idx;
	int j;
	int i;
	char *new_buffer;

	i = 0;
	idx = ft_strlen_GNL(buffer);
	j = ft_strlen(buffer);
	new_buffer = malloc((j - idx + 1) * sizeof(char));
	if(!new_buffer)
		return (NULL);
	while(buffer[idx])
	{
		new_buffer[i] = buffer[idx];
		idx++;
		i++;
	}
	return(new_buffer);
}
/* char	*get_line(int fd, char *buffer, char *stash)
{
	char	*char_tmp;
	int		size_bytes;

	size_bytes = 1;
	while (size_bytes > 0)
	{
		size_bytes = read(fd, buffer, BUFFER_SIZE);
		if (size_bytes == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (size_bytes == 0)
			break ;
		buffer[size_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		char_tmp = stash;
		stash = ft_strjoin(char_tmp, buffer);
		free(char_tmp);
		char_tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*get_line_buffer(char *line)
{
	char	*new_line;
	size_t	count;

	count = 0;
	while (line[count] != '\0' && line[count] != '\n')
		count++;
	if (line[count] == '\0' || line[count] == '\n')
		return (0);
	new_line = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*new_line == '\0')
	{
		free(new_line);
		new_line = NULL;
	}
	count++;
	new_line[count] = '\0';
	return (new_line);
}

Peudocode:
1. retorn imprime uma linha inteira;
2. verificar se o fd = 0 e o tamanho o buffer ser z= 0 - return (NULL);
3. alocar memoria tendo em conta o tamanho do buffer;
4.Repete encontar \n ou \0:
 ler o conteudo fd atraves do read ??  OUTRA FUNCAO??
5. Guardar o conteudo, copia p uma variavel(line) e limpa o buffer;
6. guarda na variavel estatica o ulimos 2 caracteres;
7.

*/