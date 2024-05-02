#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if(!buffer[0])
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	line = NULL;
	while(buffer[0])
	{
		line = ft_strjoin_GNL(line, buffer);
		if(!line)
				return(NULL);
		if(organize_buffer(buffer) == 1)
			break;
		if(read(fd, buffer, 0) < 0)
		{
			free(line);
			return(NULL);
		}
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	}
	return(line);
}

/* Peudocode:
1. retorn imprime uma linha inteira;
2. verificar se o fd = 0 e o tamanho o buffer ser z= 0 - return (NULL);
3. alocar memoria tendo em conta o tamanho do buffer;
4.Repete encontar \n ou \0:
 ler o conteudo fd atraves do read ??  OUTRA FUNCAO??
5. Guardar o conteudo, copia p uma variavel(line) e limpa o buffer;
6. guarda na variavel estatica o ulimos 2 caracteres; */