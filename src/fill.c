/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:00:02 by kosadchu          #+#    #+#             */
/*   Updated: 2019/04/22 21:00:05 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		way_size(int y, int x, int a, int b)
{
	int		i;
	int		j;
	int		res;

	j = x - b;
	(j < 0) ? j *= -1 : 0;
	i = y - a;
	(i < 0) ? i *= -1 : 0;
	res = j + i;
	return (res);
}

void	check_way(char **map, int y, int x)
{
	int		a;
	int		b;
	int		way;

	a = 0;
	while (a < g_st.msize[0])
	{
		b = 0;
		while (b < g_st.msize[1])
		{
			if (map[a][b] == g_st.p2 || map[a][b] == g_st.p2 + 32)
			{
				way = way_size(y, x, a, b);
				if (way < g_st.way)
				{
					g_st.way = way;
					g_st.send_y = y;
					g_st.send_x = x;
				}
			}
			b++;
		}
		a++;
	}
}

int		check_piece_position(char **map, char **p, int y, int x)
{
	int		a;
	int		b;
	int		y1;
	int		x1;

	a = -1;
	g_st.count = 0;
	while (++a < g_st.psize[0])
	{
		b = -1;
		while (++b < g_st.psize[1])
		{
			y1 = y - g_st.m_y;
			x1 = x - g_st.m_x;
			if (y + a > g_st.msize[0] - 1 || x + b > g_st.msize[1] - 1
			|| y + a > g_st.msize[0] - 1 || x + b > g_st.msize[1] - 1
			|| (p[a][b] != '.' && (map[y1 + a][x1 + b] == g_st.p2
			|| map[y1 + a][x1 + b] == g_st.p2 + 32)))
				return (0);
			(p[a][b] != '.' && (map[y1 + a][x1 + b] == g_st.p1
			|| map[y1 + a][x1 + b] == g_st.p1 + 32)) ? g_st.count++ : 0;
		}
	}
	(g_st.count == 1) ? check_way(map, y1, x1) : 0;
	return (0);
}

void	begin_play(char **map, char **piece)
{
	int		y;
	int		x;

	y = 0;
	piece_coord(piece);
	while (y < g_st.msize[0])
	{
		x = 0;
		while (x < g_st.msize[1])
		{
			if (y + g_st.psize[0] - 1 <= g_st.msize[0]
			|| x + g_st.psize[1] - 1 <= g_st.msize[1])
				check_piece_position(map, piece, y, x);
			x++;
		}
		y++;
	}
}
