/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:11:49 by wayden            #+#    #+#             */
/*   Updated: 2023/03/19 00:08:09 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"



void reset(void)
{
    while(get_dir(1)->zoom > 1)
        {
            get_dir(1)->zoom *= 0.95;
            update_screen(NULL);
        }   
}

void zoom(void)
{
    t_dir *dir;
    int x;
    int y;
    
    dir = get_dir(1);
    mlx_mouse_get_pos(get_mlx(1)->mlx_ptr,get_mlx(1)->win_ptr,&x,&y);
    dir->zoom *= 1.05;
    dir->x += ((double)x - WIDTH / 2) * 0.22 / (WIDTH * dir->zoom);
    dir->y += ((double)y - HEIGHT / 2) * 0.22 / (HEIGHT * dir->zoom);
     
}