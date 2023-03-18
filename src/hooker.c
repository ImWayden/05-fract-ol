/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:10:23 by wayden            #+#    #+#             */
/*   Updated: 2023/03/19 00:08:15 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int update_screen(void *param)
{
    t_dir *dir;
    
    (void)param;
    dir = get_dir(1);
    if(dir->palette >= 666)
    {
        dir->palette++;
        if(dir->palette == 672)
            dir->palette = 666;            
    }
    draw_set(get_complex(1), get_mlx(1), get_img(1),dir);
    return(0);
}

static int	destroy_app(t_mlx *mlx)
{
    mlx_destroy_image(mlx->mlx_ptr, get_img(1)->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
	return (1);
}

static int mouse_manager(int keycode, void *param)
{
    (void)param;
    if (keycode == 3)
        while(get_dir(1)->zoom < 1000000)
            (zoom(),1) && (update_screen(NULL),1);
    (keycode == 4) && (zoom(),1);
    if (keycode == 5 && get_dir(1)->zoom >= 1.00)
        get_dir(1)->zoom *= 0.95; 
    return(0);
}

static int keyboard_manager(int keycode, void *param)
{
    (void)param;
    (keycode == XK_Left) && ((get_dir(1)->x -= 0.1*(1/get_dir(1)->zoom)),1);
    (keycode == XK_Right) && ((get_dir(1)->x += 0.1*(1/get_dir(1)->zoom)),1);
    (keycode == XK_Up) && ((get_dir(1)->y -= 0.1*(1/get_dir(1)->zoom)),1);
    (keycode == XK_Down) && ((get_dir(1)->y += 0.1*(1/get_dir(1)->zoom)),1);
    (keycode == XK_w) && ((get_dir(1)->palette = 0),1);
    (keycode == XK_x) && (get_dir(1)->palette = 1);
    (keycode == XK_c) && (get_dir(1)->palette = 2);
    (keycode == XK_v) && (get_dir(1)->palette = 3);
    (keycode == XK_b) && (get_dir(1)->palette = 4);
    (keycode == XK_n) && (get_dir(1)->palette = 5);
    ((keycode == XK_comma) && (get_dir(1)->palette = 6));
    ((keycode == XK_o) && (get_dir(1)->palette = 666));
    (keycode == XK_r) && (reset(),1);   
    (keycode == XK_q) && ((get_complex(1)->i -= 0.1),1);
    (keycode == XK_d) && ((get_complex(1)->i += 0.1),1);
    (keycode == XK_a) && ((get_complex(1)->r -= 0.1),1);
    (keycode == XK_e) && ((get_complex(1)->r += 0.1),1);
    (keycode == XK_Escape) && (destroy_app(get_mlx(1))) && (exit(0),1);
    (keycode == XK_p) && get_dir(1)->palette < 12 && (get_dir(1)->palette++,1);
    (keycode == XK_m) && get_dir(1)->palette > 0 && get_dir(1)->palette <= 12 
    && (get_dir(1)->palette--,1);
    return(0);
}

void init_hook(void)
{
    t_mlx *mlx;
    mlx = get_mlx(1);
    mlx_mouse_hook(mlx->win_ptr, &mouse_manager, NULL);
    mlx_key_hook(mlx->win_ptr, &keyboard_manager, NULL);
    mlx_hook(mlx->win_ptr, 17, 0, destroy_app, mlx);
    mlx_loop_hook(get_mlx(1)->mlx_ptr, &update_screen, NULL);
}
