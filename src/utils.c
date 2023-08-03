/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:11:49 by wayden            #+#    #+#             */
/*   Updated: 2023/08/03 23:50:06 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	reset(void)
{
	g_dr(1)->zoom = 1;
	update_screen(NULL);
}

void lock_mouse()
{
    t_dir *dir;
    dir = get_dir(1);
    if(dir->lock)
        dir->lock = 0;
    else
        dir->lock++;
}

void check_reset(t_dir *dir)
{
    if(dir->reset)
    {
        if(dir->zooming)
            dir->zooming = 0;
        if(dir->zoom > 1)
            zoom(0.95);
        else
            dir->reset = 0;
    }
}
void check_zooming(t_dir *dir)
{
    if(dir->zooming)
    {
        if(dir->reset)
            dir->reset = 0;
        if(dir->zoom < 1000000)
            zoom(1.05);
        else
            dir->zooming = 0;
    }   
}


void reset(void)
{
    t_dir *dir;

    dir = get_dir(1);
    if(dir->reset)
        dir->reset = 0;
    else
        dir->reset++;
}

void zoom(double facteur)
{
    t_dir *dir;
    int x;
    int y;
    
    dir = get_dir(1);
    mlx_mouse_get_pos(get_mlx(1)->mlx_ptr,get_mlx(1)->win_ptr,&x,&y);
    dir->zoom *= facteur;
    dir->x += ((double)x - WIDTH / 2) * 0.22 / (WIDTH * dir->zoom);
    dir->y += ((double)y - HEIGHT / 2) * 0.22 / (HEIGHT * dir->zoom);
     
}
