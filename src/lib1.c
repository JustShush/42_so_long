/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:21:16 by dimarque          #+#    #+#             */
/*   Updated: 2023/08/04 11:39:01 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	a = s1[i];
	b = s2[i];
	while (s1[i] != '\0' && (s1[i] == s2[i]))
	{
		i++;
		a = s1[i];
		b = s2[i];
	}
	return (a - b);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}