/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:33:01 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/03 15:37:24 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		findnbrlen(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void		convert_process(long n, char *nbr, int i, int len)
{
	nbr[len - i] = (n % 10) + '0';
	if (n > 9)
		convert_process(n / 10, nbr, ++i, len);
}

char			*ft_itoa(int n)
{
	char	*nbr;
	int		len;
	int		i;
	long	l_nb;

	len = findnbrlen((long)n);
	if (!(nbr = malloc(sizeof(*nbr) * (len + 1))))
		return (NULL);
	l_nb = n;
	i = 0;
	if (n < 0)
	{
		l_nb = (long)n * -1;
		nbr[i] = '-';
	}
	convert_process(l_nb, nbr, i, len - 1);
	nbr[len] = '\0';
	return (nbr);
}
