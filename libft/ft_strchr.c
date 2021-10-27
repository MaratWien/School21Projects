/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:44:18 by hfunctio          #+#    #+#             */
/*   Updated: 2020/10/30 15:19:02 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char i;

	i = (char)c;
	while (*s)
	{
		if (*s == i)
			return ((char*)s);
		s++;
	}
	if (*s == 0 && i == 0)
		return ((char*)s);
	return (0);
}