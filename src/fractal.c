/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:28:55 by wayden            #+#    #+#             */
/*   Updated: 2023/03/19 00:08:18 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static double scale(int x, int y, char letter)
{
    double c;
    double d;

    c = -2;
    d = 2;
    if(letter == 'x')
        return((double)x * (d - c) / WIDTH + c);
    if(letter == 'y')
        return((double)y * (d - c ) / HEIGHT + c);
    return(0);
}

static int julia(t_complex *z, t_complex *c, double max_iter)
{
    double iter;
    t_complex z_new;

    iter = 0;
    while (iter < max_iter)
    {
        z_new.r = z->r * z->r - z->i * z->i + c->r;
        z_new.i = 2 * z->r * z->i + c->i;
        *z = z_new;
        if (z->r * z->r + z->i * z->i >= 4)
            break;
        iter++;
    }
    if (iter == max_iter)
        return (0x000000);
    return (get_color(max_iter,iter));
}

static int burning_ship(t_complex c, double max_iter)
{
    double iter;
    t_complex z;

    iter = 0;
    z = (t_complex){};
    while (iter < max_iter)
    {
       	if (z.r * z.r + z.i * z.i >= 4)
			break;
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		z = (t_complex){
			.r = z.r * z.r - z.i * z.i + c.r,
			.i = 2 * z.r * z.i + c.i
		};
		iter++;
    }
    if (iter == max_iter)
        return (0x000000);
    return (get_color(max_iter,iter));
}

static int mandelbrot(t_complex *c, double max_iter)
{
    double iter;
    t_complex z; 
    t_complex z_new;

    iter = 0;
    z = (t_complex){};
    while (iter < max_iter)
    {
        z_new.r = z.r * z.r - z.i * z.i + c->r;
        z_new.i = 2 * z.r * z.i + c->i;
        z = z_new;
        if (z.r * z.r + z.i * z.i >= 4)
            break;
        iter++;
    }
    if (iter == max_iter)
        return (0x000000);
    return (get_color(max_iter,iter));
}

void draw_set(t_complex *c, t_mlx *mlx, t_img *img,t_dir *dir)
{
    int x;
    int y;
    
    t_complex z;
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            z.r = scale(x,y,'x')/ dir->zoom + dir->x;
            z.i = scale(x,y,'y')/ dir->zoom + dir->y;
            if(dir->fractal == 1)
                *(unsigned int *)(img->addr + (y * img->line_length + x 
                * (img->bits_per_pixel / 8))) = julia(&z, c, dir->iter_max);
            else if(dir->fractal == 2)
                *(unsigned int *)(img->addr + (y * img->line_length + x 
                * (img->bits_per_pixel / 8))) = mandelbrot(&z, dir->iter_max);
            else if(dir->fractal == 3)
                *(unsigned int *)(img->addr + (y * img->line_length + x 
                * (img->bits_per_pixel / 8))) = burning_ship(z, dir->iter_max);
        }
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, get_img(1)->img, 0, 0);
}
