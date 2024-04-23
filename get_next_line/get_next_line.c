#include "get_next_line.h"

char	*get_line(int fd, char *buffer, char *stash);
char	*get_line_buffer(char *line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, stash);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash = get_line_buffer(line);
	return (line);
}
char	*get_line(int fd, char *buffer, char *stash)
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
char	*ft_strdup(const char *s)
{
	char	*dest;
	int		size_len;
	int		i;

	size_len = ft_strlen(s) + 1;
	i = 0;
	dest = malloc((size_len) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("teste.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha lida: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
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