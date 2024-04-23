#include "get_next_line.h"

static char	*fill_the_buffer(int fd, char *storage, char *buffer);
static char *clean_storage(char *line);
char	*ft_strchr(const char *s, int c);
/*
Confirm if there is fd is 0 or buffer is 0;
Then alocatte memory for the buffer and calls a function to copy the information to the line until find \n or \0
Return the line that was read or NULL if ther is nothing to read or an error occured;
To obtain the line we call
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		// por buffer_size = 0 e/ou fd = 0
		//printf("Buffer size or fd invalid");
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		//fprintf(stderr, "Erro: Falha ao alocar memória para o buffer\n");
		// usar cc , depois ulimit -v 1000 (1KB) ./a.out
		return (NULL);
	}
	line = fill_the_buffer(fd, storage, buffer);
	free(buffer);
	buffer = NULL;
	if(!line)
        return(NULL);
    storage = clean_storage(line);
    return (line);
}

/*
it will use the read  function to read the buffer
Repeat the loop until finds the \0 or \n
using the strjoin to concatenate the new inf of buffer and the storage.
Return the stactic variable that maintais the content the functions
repete o buffer e copia o conteudo para a variavel estarica ate encontrar o nulo
*/
static char	*fill_the_buffer(int fd, char *storage, char *buffer)
{
	char	*temp_storage;
	int		bytes_buffer;

	bytes_buffer = 1;
	while (bytes_buffer > 0)
	{
		bytes_buffer = read(fd, buffer, BUFFER_SIZE);
		if (bytes_buffer == -1)
		{
			free(storage);
			return (NULL);
		}
		else if (bytes_buffer == 0)
			break ;
		buffer[bytes_buffer] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp_storage = storage;
		storage = ft_strjoin(temp_storage, buffer);
		free(temp_storage);
		temp_storage = NULL;
		// mudar isto: considerar uma substr ?
         if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}
static char *clean_storage(char *line)
{
    size_t idx;
    char *new_storage;
	size_t len_new_storage;

    idx = 0;
	while(line[idx] != '\0' && line[idx] != '\n')
        idx++;
	if(line[idx] == '\0' && line[idx] == '\n')
		return(0);
	len_new_storage = ft_strlen(line) - idx;
    new_storage = ft_substr(line, idx + 1, len_new_storage);
    if(*new_storage == 0)
	{
		free(new_storage);
		new_storage = NULL;
	}
	idx++;
	new_storage[idx] = '\0';
    return(new_storage);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/*temos um texto,
	um tamanho de buffer no buffer fica o que imprime e vai p uma variavel static que guarda a nova inf
		- strjoin return nr do BUFFER strlen ?
																																				// limpa o BUFFER
	repete ate encontrar uma \n ou \0 quando encontra copia p uma nova variavel line
		/ usar o strchr p encontrar o \n ou \0
	? e depois o substr
	? ou so o substr limpa o storage a partir ate ao \0 ou \n /
		strchr

			ft_strlen -
	        conta o nr de characterers ft_strchr
		- localiza um caracter na string ft_strdup
		- salva uma copia da string ft_substr
		- extrai um substring de uma string ft_strjoin -
	concatena duas strings

		Read -
	le de um ficheiro e a guarda o que leu,
	assim como o numero de palavras lidas numa variavel para depois continuar a partir dai,
		quando termina retorna 0,

	Pseudo
		- code : no main ter um ficheiro para ler que vai ser aberto com a funcao read.No main vamos correr a funcao que criamos get_next_line;
1. retorn imprime uma linha inteira;
2. verificar se o fd = 0 e o tamanho o buffer ser z = 0 - return (NULL);
3. alocar memoria tendo em conta o tamanho do buffer;
4. Repete ate encontar \n ou \0 : ler o conteudo fd atraves do read ? ? OUTRA FUNCAO ? ? 5. Guardar o conteudo,
	copia p uma storage e limpa o buffer;
6. guarda na variavel estatica o ultimos 2 caracteres;
7

	temos um texto,
	um tamanho de buffer no buffer fica o que imprime e vai p uma variavel static que guarda a nova inf strjoin ? return nr do BUFFER strlen ? limpa o BUFFER repete ate encontrar uma \n ou \0 quando encontra copia p uma nova variavel line
		/ usar o strchr p encontrar o \n ou \0 ? e depois o substr ? ou so o substr limpa o storage a partir ate ao \0 ou \n
		/ strchr
*/