/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:33:01 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/13 17:14:08 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		findnbrlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void		convert_process(unsigned int n, char *nbr, int i, int len)
{
	nbr[len - i] = (n % 10) + '0';
	if (n > 9)
		convert_process(n / 10, nbr, ++i, len);
}

char			*ft_itoa_ui(unsigned int n)
{
	char				*nbr;
	int					len;
	int					i;

	len = findnbrlen(n);
	if (!(nbr = malloc(sizeof(*nbr) * (len + 1))))
		return (NULL);
	i = 0;
	convert_process(n, nbr, i, len - 1);
	nbr[len] = '\0';
	return (nbr);
}
