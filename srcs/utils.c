/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:44:22 by taehykim          #+#    #+#             */
/*   Updated: 2022/08/23 17:44:23 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_final(t_map_info *map_info)
{
	int	i;

	i = 0;
	while (map_info->map[i])
	{
		free(map_info->map[i]);
		map_info->map[i] = NULL;
		i++;
	}
	if (map_info->map_line)
	{
		free(map_info->map);
		map_info->map_line = NULL;
	}
	map_info = NULL;
}

void	ft_free(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	exit_error(char *msg)
{
	printf("Error\n");
	printf("%s", msg);
	exit(1);
}
