/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:11:29 by gacavali          #+#    #+#             */
/*   Updated: 2024/04/29 15:12:13 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(int n, int j)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		j += ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		j = ft_putnbr(n / 10, j);
		j = ft_putnbr(n % 10, j);
	}
	else
		j += ft_putchar(n + '0');
	return (j);
}
