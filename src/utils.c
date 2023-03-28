/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:11:49 by wayden            #+#    #+#             */
/*   Updated: 2023/03/28 02:55:41 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	reset(void)
{
	g_dr(1)->zoom = 1;
	update_screen(NULL);
}

void	zoom(void)
{
	t_dir	*dir;
	int		x;
	int		y;

	dir = g_dr(1);
	mlx_mouse_get_pos(get_mlx(1)->mlx_ptr, get_mlx(1)->win_ptr, &x, &y);
	dir->zoom *= 1.05;
	dir->x += ((double)x - WIDTH / 2) * 0.22 / (WIDTH * dir->zoom);
	dir->y += ((double)y - HEIGHT / 2) * 0.22 / (HEIGHT * dir->zoom);
}

void	draw_set(t_mlx *mlx, t_img *img, t_dir *dir)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			choose_fractal(x, y, img, dir);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, get_img(1)->img, 0, 0);
}
