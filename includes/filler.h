/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:50:32 by kosadchu          #+#    #+#             */
/*   Updated: 2019/04/12 14:59:07 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_st
{
	int			send_x;
	int			send_y;
	char		p1;
	char		p2;
	int			msize[2];
	int			psize[2];
	int			m_y;
	int			m_x;
	int			way;
	int			count;
}				t_st;

int				g_fds;
t_st			g_st;
char			**make_map_piece(int y, int x);
char			**save_map(int my, char *str, char **map, char c);
void			save_piece_size(void);
void			save_map_size(char *str);
void			begin_play(char **map, char **piece);
void			piece_coord(char **piece);

#endif
