/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:15:41 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/04 11:38:52 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ok(char *line, char buffer)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen2(line) + 2));
	while (line && line[i])
	{
		temp[i] = line[i];
		i++;
	}
	temp[i++] = buffer;
	temp[i] = '\0';
	//line = temp;
	free(line);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buffer;
	char		*line;

	line = NULL;
	if (read(fd, NULL, 0) < 0)
		return (ctrl_l(&buffer));
	while (read(fd, &buffer, 1))
	{
		//printf("%c\n", buffer);
		line = ok(line, buffer);
		if (line[ft_strlen(line) - 1] == '\n')
			break ;
	}
	return (line);
}

/* int main(void)
{
	int fd;
	char *line;
	fd = open("test.txt", O_RDONLY);
	//printf("%s", get_next_line(fd));
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
} */