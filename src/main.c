/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:58:50 by kosadchu          #+#    #+#             */
/*   Updated: 2019/04/12 14:58:57 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_variables(void)
{
	g_st.msize[0] = 0;
	g_st.msize[1] = 0;
	g_st.psize[0] = 0;
	g_st.psize[1] = 0;
	g_st.way = 10000;
	g_st.send_x = 0;
	g_st.send_y = 0;
}

char	**create_map_piece(char c, int y, int x)
{
	char	**arr;
	int		i;
	int		my;
	char	*str;

	i = 0;
	my = 0;
	arr = make_map_piece(y, x);
	while (i < y && get_next_line(0, &str))
	{
		arr = save_map(my, str, arr, c);
		i++;
		my++;
		ft_strdel(&str);
	}
	return (arr);
}

void	print_res(void)
{
	char	*res;

	res = ft_itoa(g_st.send_y);
	ft_putstr(res);
	write(1, " ", 1);
	ft_strdel(&res);
	res = ft_itoa(g_st.send_x);
	ft_putstr(res);
	write(1, "\n", 1);
	ft_strdel(&res);
	free_variables();
}

void	pars_map(char *str)
{
	char	**map;
	char	**piece;

	save_map_size(str);
	map = create_map_piece('m', g_st.msize[0], g_st.msize[1]);
	save_piece_size();
	piece = create_map_piece('p', g_st.psize[0], g_st.psize[1]);
	begin_play(map, piece);
	ft_free_array(map);
	ft_free_array(piece);
	print_res();
}

int		main(void)
{
	char	*str;

	str = NULL;
	free_variables();
	get_next_line(0, &str);
	if (ft_strstr(str, "$$$ exec p1"))
	{
		g_st.p1 = 'O';
		g_st.p2 = 'X';
	}
	if (ft_strstr(str, "$$$ exec p2"))
	{
		g_st.p1 = 'X';
		g_st.p2 = 'O';
	}
	ft_strdel(&str);
	while (get_next_line(0, &str))
	{
		pars_map(str);
		ft_strdel(&str);
	}
	return (0);
}
