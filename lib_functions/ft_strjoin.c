/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anematol <anematol@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:37:17 by anematol          #+#    #+#             */
/*   Updated: 2025/08/30 16:10:59 by anematol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i_dest;
	int	i_src;

	i_dest = 0;
	i_src = 0;
	while (dest[i_dest] != '\0')
		i_dest++;
	while (src[i_src] != '\0')
	{
		dest[i_dest] = src[i_src];
		i_src++;
		i_dest++;
	}
	dest[i_dest] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_length;
	char	*return_str;

	total_length = 1;
	i = -1;
	while (++i < size)
	{
		total_length += ft_strlen(strs[i]);
		if (i < size - 1)
			total_length += ft_strlen(sep);
	}
	i = -1;
	return_str = ft_calloc(total_length, sizeof(char));
	if (!return_str)
		return (NULL);
	while (++i < size)
	{
		ft_strcat(return_str, strs[i]);
		if (i < size - 1)
			ft_strcat(return_str, sep);
	}
	if (size == 0)
		*return_str = '\0';
	return (return_str);
}
/*
int main()
{
	#include <stdio.h>
	#include <string.h>

	char *str1 = "42Berlin";
	char *str2 = "42Paris";
	char *str3 = "42Wolfsburg";
	char *str4 = "42Silicon Valley (deprecated)";

	char *sep = " and there is ";
	int size = 4;
	char *strs[size];
	strs[0] = str1;
	strs[1] = str2;
	strs[2] = str3;
	strs[3] = str4;

	char *concat_str = ft_strjoin(size, strs, sep);

	printf("%s\n", concat_str);
	free(concat_str);
}
*/
