/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:16:09 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/09 21:36:23 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	char	*copy;

	copy = s;
	while (n--)
		*copy++ = '\0';
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	long int	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		res *= 10;
		res += nptr[i] - 48;
		i++;
	}
	return (res * sign);
}

char	*ft_strchr(const char *s, int c)
{	
	int				i;
	unsigned char	c1;

	i = 0;
	c1 = c;
	while (s[i])
	{
		if (s[i] == c1)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c1)
		return ((char *)s + i);
	return (NULL);
}

char	**ft_recursive_split(char *str, char *arr[], int count, char *charset)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = 0;
	while (str && *str && ft_strchr(charset, *str))
		str++;
	while (str && str[i] && !ft_strchr(charset, *str))
		i++;
	if (i > 0)
		new_str = (char *)malloc(i + 1);
	if (new_str)
		new_str[i] = 0;
	i = 0;
	while (new_str && str && *str && !ft_strchr(charset, *str))
		new_str[i++] = *str++;
	if (new_str)
		arr = ft_recursive_split(str, arr, count + 1, charset);
	else
		arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr)
		arr[count] = new_str;
	return (arr);
}
