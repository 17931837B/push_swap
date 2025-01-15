/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:20:00 by tobaba            #+#    #+#             */
/*   Updated: 2024/04/17 14:20:00 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *ptr, unsigned int num)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (num)
	{
		*p = 0;
		num--;
		p++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, unsigned int num)
{
	unsigned char		*cpy_d;
	const unsigned char	*cpy_s;

	if (dest == NULL && src == NULL)
		return (dest);
	cpy_d = dest;
	cpy_s = src;
	cpy_s = (unsigned char *)cpy_s;
	while (num)
	{
		*cpy_d = *cpy_s;
		cpy_d++;
		cpy_s++;
		num--;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1));
	ft_memcpy(res + ft_strlen(s1), s2, ft_strlen(s2));
	return (res);
}
