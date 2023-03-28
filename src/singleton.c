/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:22:36 by wayden            #+#    #+#             */
/*   Updated: 2023/03/28 01:07:15 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

t_dir	*g_dr(int is_initialized)
{
	static t_dir	dir;

	if (!is_initialized)
	{
		dir.zoom = 1;
		dir.x = 0;
		dir.y = 0;
		dir.iter_max = 50;
		dir.palette = 0;
		dir.psy = 0;
	}
	return (&dir);
}

t_complex	*get_complex(int is_initialized)
{
	static t_complex	c;

	if (!is_initialized)
	{
		c.r = -0.767;
		c.i = -0.192;
	}
	return (&c);
}

t_mlx	*get_mlx(int is_initialized)
{
	static t_mlx	mlx;

	if (!is_initialized)
	{
		mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	}
	return (&mlx);
}

t_img	*get_img(int is_initialized)
{
	static t_img	img;

	if (!is_initialized)
	{
		img.img = mlx_new_image(get_mlx(1)->mlx_ptr, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
	}
	return (&img);
}
