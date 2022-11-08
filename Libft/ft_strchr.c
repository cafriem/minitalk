/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:30:41 by cafriem           #+#    #+#             */
/*   Updated: 2022/05/28 15:11:39 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	c1;

	c1 = 0;
	while (s[c1] != (char)c && s[c1] != '\0')
		c1++;
	if (s[c1] == '\0' && c != '\0')
		return (NULL);
	return (&((char *)s)[c1]);
}

/*#include <stdio.h>
#include <unistd.h>
int main()
{
	char l = 'm';
	char s1[] = "Hello my friend";

	printf("%s",ft_strchr(s1, l));
}*/
