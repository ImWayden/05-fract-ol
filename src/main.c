/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:48:04 by wayden            #+#    #+#             */
/*   Updated: 2023/03/19 10:55:39 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"



static int print_e_manual(int i)
{
    if(i == 0)
    { 
        ft_printf("Usage : ./fractol [Julia] [C Real] [C Imag] [iter_max]\n");
        ft_printf("   or : ./fractol [Mandelbrot] [iter_max]\n");
        ft_printf("   or : ./fractol [Burning_ship] [iter_max]\n");
        ft_printf("--command : to get a list of keybind\n");
    }
    if(i == 1)
    {
        printf("\n\nright click  : auto zoom in\n");
        printf("moushe wheel : zoom to cursor\n");
        printf("      r      : auto dezoom from pos\n"); 
        printf("arrow_keys   : moves throught image\n");
        printf("w x c v b n ,: different color\n");
        printf("p and m      : precedent and next color\n"); 
        printf("a and e      : modify constant real part\n"); 
        printf("q and d      : modify constant imgi part\n"); 
        printf("      o      : don't press if epileptic\n\n\n"); 
        
    }
    destroy_app(get_mlx(1));
    return (0);
}

static int verify_argument(int argc,char **argv)
{
    t_dir *dir;

    dir = get_dir(1);
    if(argc < 2)
       return(print_e_manual(0));
    if(!ft_strncmp(argv[1],"Julia",20))
    {
        dir->fractal = 1;
        if(argc >= 3)
            get_complex(1)->r = atof(argv[2]);
        if(argc >= 4)
            get_complex(1)->i = atof(argv[3]);
        if(argc >= 5)
            dir->iter_max = atof(argv[4]);
    }    
    if(!ft_strncmp(argv[1],"Mandelbrot",20))
        dir->fractal = 2;
    if(!ft_strncmp(argv[1],"Burning_ship",20))
        dir->fractal = 3;
    if(dir->fractal > 1 && argc >= 3)
        dir->iter_max = atof(argv[2]);
    if(!ft_strncmp(argv[1],"--command",20))
        return(print_e_manual(1));
    return(1);
}

int main(int argc, char **argv)
{
    get_dir(0);
    get_complex(0);
    get_mlx(0);
    get_img(0);
    if(!verify_argument(argc,argv))
        return(0);
    init_hook();
    mlx_loop(get_mlx(1)->mlx_ptr);
    return (0);
}


