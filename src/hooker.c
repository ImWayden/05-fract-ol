/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:10:23 by wayden            #+#    #+#             */
/*   Updated: 2023/03/28 02:07:01 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	update_screen(void *param)
{
	t_dir	*dir;

	(void)param;
	dir = g_dr(1);
	if (dir->palette >= 666)
	{
		dir->palette++;
		if (dir->palette == 672)
			dir->palette = 666;
	}
	draw_set(get_mlx(1), get_img(1), dir);
	return (0);
}

int	destroy_app(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, get_img(1)->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
	return (1);
}

static int	mouse_manager(int keycode, void *param)
{
	(void)param;
	if (keycode == 3)
		while (g_dr(1)->zoom < 1000000)
			(void)((zoom(), 1) && (update_screen(NULL), 1));
	(void)((keycode == 4) && (zoom(), 1));
	if (keycode == 5 && g_dr(1)->zoom >= 1.00)
		g_dr(1)->zoom *= 0.95;
	return (0);
}

static int	keyboard_manager(int keycode, void *param)
{
	(void)param;
	(void)((keycode == XK_Left) && ((g_dr(1)->x -= 0.1 * (1 / g_dr(1)->zoom))));
	(void)((keycode == XK_Right) && (g_dr(1)->x += 0.1 * (1 / g_dr(1)->zoom)));
	(void)((keycode == XK_Up) && (g_dr(1)->y -= 0.1 * (1 / g_dr(1)->zoom)));
	(void)((keycode == XK_Down) && (g_dr(1)->y += 0.1 * (1 / g_dr(1)->zoom)));
	(void)((keycode == XK_z) && ((g_dr(1)->palette = 0), 1));
	(void)((keycode == XK_x) && (g_dr(1)->palette = 1));
	(void)((keycode == XK_c) && (g_dr(1)->palette = 2));
	(void)((keycode == XK_v) && (g_dr(1)->palette = 3));
	(void)((keycode == XK_b) && (g_dr(1)->palette = 4));
	(void)((keycode == XK_n) && (g_dr(1)->palette = 5));
	(void)(((keycode == XK_m) && (g_dr(1)->palette = 6)));
	(void)(((keycode == XK_o) && (g_dr(1)->palette = 666)));
	(void)((keycode == XK_r) && (reset(), 1));
	(void)((keycode == XK_a) && (get_complex(1)->i -= 0.1));
	(void)((keycode == XK_d) && (get_complex(1)->i += 0.1));
	(void)((keycode == XK_s) && (get_complex(1)->r -= 0.1));
	(void)((keycode == XK_w) && (get_complex(1)->r += 0.1));
	(void)((keycode == XK_Escape) && (destroy_app(get_mlx(1))) && (exit(0), 1));
	(void)((keycode == XK_KP_Add) && g_dr(1)->palette < 12
			&& g_dr(1)->palette++);
	(void)((keycode == XK_KP_Subtract) && g_dr(1)->palette > 0
			&& g_dr(1)->palette <= 12 && (g_dr(1)->palette--, 1));
	return (0);
}

void	init_hook(void)
{
	t_mlx	*mlx;

	mlx = get_mlx(1);
	mlx_mouse_hook(mlx->win_ptr, &mouse_manager, NULL);
	mlx_key_hook(mlx->win_ptr, &keyboard_manager, NULL);
	mlx_hook(mlx->win_ptr, 17, 0, destroy_app, mlx);
	mlx_loop_hook(get_mlx(1)->mlx_ptr, &update_screen, NULL);
}
