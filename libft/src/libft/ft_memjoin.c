/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:53:26 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/08 18:53:41 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(const void *a,
				size_t an,
				const void *b,
				size_t bn)
{
	void	*s;

	if (!(s = malloc((a ? an : 0) + (b ? bn : 0))))
		return (NULL);
	if (a)
		ft_memcpy(s, a, an);
	if (b)
		ft_memcpy((void *)((char *)s + an), b, bn);
	return (s);
}

void	*ft_memjoin_clr(void *a,
					size_t an,
					void *b,
					size_t bn)
{
	void	*s;

	if (!(s = malloc((a ? an : 0) + (b ? bn : 0))))
		return (NULL);
	if (a)
		ft_memcpy(s, a, an);
	if (b)
		ft_memcpy((void *)((char *)s + an), b, bn);
	free(a);
	return (s);
}
