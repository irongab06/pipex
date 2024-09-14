/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:10:32 by gacavali          #+#    #+#             */
/*   Updated: 2024/05/06 11:57:52 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_addr(unsigned long n, char *base, int j)
{
	if (n >= 16)
	{
		j = ft_putnbr_addr(n / 16, base, j);
		j = ft_putnbr_addr(n % 16, base, j);
	}
	else
		j += ft_putchar(base[n]);
	return (j);
}
