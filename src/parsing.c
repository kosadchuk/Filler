/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:57:01 by kosadchu          #+#    #+#             */
/*   Updated: 2019/04/12 16:57:03 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	piece_coord(char **piece)
{
	int		i;
	int		j;

	i = 0;
	g_st.m_y = 10000;
	g_st.m_x = 10000;
	while (i < g_st.psize[0])
	{
		j = 0;
		while (j < g_st.psize[1])
		{
			if (piece[i][j] == '*')
			{
				(i < g_st.m_y) ? g_st.m_y = i : 0;
				(j < g_st.m_x) ? g_st.m_x = j : 0;
			}
			j++;
		}
		i++;
	}
}

char	**make_map_piece(int y, int x)
{
	char	**map;
	int		i;

	i = 0;
	map = (char**)ft_memalloc(sizeof(char*) * y + 1);
	while (i < y)
	{
		map[i] = (char*)ft_memalloc(sizeof(char) * x + 1);
		map[i][x] = '\0';
		i++;
	}
	map[y] = 0;
	return (map);
}

char	**save_map(int my, char *str, char **map, char c)
{
	int		i;
	int		mx;

	(c == 'm') ? i = 4 : 0;
	(c == 'p') ? i = 0 : 0;
	mx = 0;
	while (str[i] != '\0')
	{
		map[my][mx] = str[i];
		i++;
		mx++;
	}
	return (map);
}

void	save_map_size(char *str)
{
	str = str + 8;
	g_st.msize[0] = ft_atoi(str);
	while (*str != 32)
		str++;
	g_st.msize[1] = ft_atoi(str);
	get_next_line(0, &str);
	ft_strdel(&str);
}

void	save_piece_size(void)
{
	char	*str;
	char	*tmp;

	get_next_line(0, &str);
	tmp = str;
	str += 6;
	g_st.psize[0] = ft_atoi(str);
	while (*str != 32)
		str++;
	g_st.psize[1] = ft_atoi(str);
	ft_strdel(&tmp);
}
