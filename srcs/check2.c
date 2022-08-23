/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:43:52 by taehykim          #+#    #+#             */
/*   Updated: 2022/08/23 17:43:54 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_white_line(char *map_line)
{
	int	i;

	i = 0;
	if (map_line[0] == '\n')
		exit_error("Map started with a newline\n");
	while (map_line[i + 1])
	{
		if (!ft_strncmp(&map_line[i], "\n\n", 2))
			exit_error("Map has newline at least 1\n");
		i++;
	}
}
