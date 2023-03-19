/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:27:34 by wayden            #+#    #+#             */
/*   Updated: 2023/03/19 10:32:06 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H


#include "./Libs/Libft/header/libft.h"
#include "mlx.h"
#include <math.h>
#include <X11/keysym.h>
#include <stdio.h>

#define WIDTH 700
#define HEIGHT 700

#define V_DK_BLUE 0x000040
#define DK_BLUE 0x000080
#define DKR_BLUE 0x0000A0
#define BLUE 0x0000FF
#define LGR_BLUE 0x3333FF
#define LG_BLUE 0x6666FF

#define V_DK_YELLOW 0x404000
#define DK_YELLOW 0x808000
#define DKR_YELLOW 0xA0A000
#define YELLOW 0xFFFF00
#define LGR_YELLOW 0xFFFF33
#define LG_YELLOW 0xFFFF66

#define V_DK_GREEN 0x004000
#define DK_GREEN 0x008000
#define DKR_GREEN 0x00A000
#define GREEN 0x00FF00
#define LGR_GREEN 0x33FF33
#define LG_GREEN 0x66FF66

#define V_DK_MAGENTA 0x400040
#define DK_MAGENTA 0x800080
#define DKR_MAGENTA 0xA000A0
#define MAGENTA 0xFF00FF
#define LGR_MAGENTA 0xFF33FF
#define LG_MAGENTA 0xFF66FF

#define LG_CYAN 0x66FFFF
#define LGR_CYAN 0x33FFFF
#define CYAN 0x00FFFF
#define DK_CYAN 0x00CCCC
#define DKR_CYAN 0x008080
#define V_DK_CYAN 0x004040

#define V_DK_RED 0x400000
#define DK_RED 0x800000
#define DKR_RED 0xA00000
#define RED 0xFF0000
#define LGR_RED 0xFF3333
#define LG_RED 0xFF6666

#define WHITE 0xFFFFFF
#define LG_GRAY 0xC0C0C0
#define GRAY 0x808080
#define DK_GRAY 0x404040
#define AL_GRAY 0x202020
#define BLACK 0x000000

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_mlx
{
    void *mlx_ptr;
    void *win_ptr;

}   t_mlx;

typedef struct s_palette
{
    int col1;
    int col2;
    int col3;
    int col4;
    int col5;
    int col6;
}   t_palette;

typedef union s_color {
	int	hex;
	struct
	{
		char	b;
		char	g;
		char	r;
		char	a;
	};
}	t_color;

typedef struct s_dir
{
    double iter_max;
    double x;
    double y;
    double zoom;
    int    fractal;
    int     palette;
    int     psy;
}   t_dir;

t_dir* get_dir(int is_initialized);
t_complex *get_complex(int is_initialized);
t_mlx *get_mlx(int is_initialized);
t_img *get_img(int is_initialized);

int get_color(double max_iter, double iter);
void draw_set(t_complex *c, t_mlx *mlx, t_img *img,t_dir *dir);

void init_hook(void);

void reset(void);
void zoom(void);

int update_screen(void *param);
int	destroy_app(t_mlx *mlx);

#endif