/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:27:15 by wayden            #+#    #+#             */
/*   Updated: 2023/03/28 01:14:16 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static int	gradient_color(int start_color, int end_color, double percent)
{
	t_color	color;

	color.r = ((start_color & 0xFF0000) >> 16) * (1 - percent)
		+ ((end_color & 0xFF0000) >> 16) * percent;
	color.g = ((start_color & 0xFF00) >> 8) * (1 - percent)
		+ ((end_color & 0xFF00) >> 8) * percent;
	color.b = (start_color & 0xFF) * (1 - percent) + (end_color & 0xFF)
		* percent;
	color.a = 0;
	return (color.hex);
}

static int	color_picker(double max_iter, double iter, t_palette pal)
{
	float	hue;
	t_color	color;

	hue = iter / max_iter * 360;
	if (hue < 30)
		color.hex = gradient_color(0x000000, pal.col1, hue / 30);
	else if (hue < 60)
		color.hex = gradient_color(pal.col1, pal.col2, hue / 60);
	else if (hue < 120)
		color.hex = gradient_color(pal.col2, pal.col3, (hue - 60) / 60);
	else if (hue < 180)
		color.hex = gradient_color(pal.col3, pal.col4, (hue - 120) / 60);
	else if (hue < 240)
		color.hex = gradient_color(pal.col4, pal.col5, (hue - 180) / 60);
	else
		color.hex = gradient_color(pal.col5, pal.col6, (hue - 240) / 120);
	return (color.hex);
}

static void	inti_pal(t_palette *pals)
{
	pals[0] = (t_palette){BLACK, AL_GRAY, DK_GRAY, GRAY, WHITE, WHITE};
	pals[1] = (t_palette){RED, YELLOW, GREEN, BLUE, CYAN, MAGENTA};
	pals[2] = (t_palette){YELLOW, GREEN, BLUE, CYAN, MAGENTA, RED};
	pals[3] = (t_palette){GREEN, BLUE, CYAN, MAGENTA, RED, YELLOW};
	pals[4] = (t_palette){BLUE, CYAN, MAGENTA, RED, YELLOW, GREEN};
	pals[5] = (t_palette){CYAN, MAGENTA, RED, YELLOW, GREEN, BLUE};
	pals[6] = (t_palette){MAGENTA, RED, YELLOW, GREEN, BLUE, CYAN};
	pals[7] = (t_palette){V_DK_RED, DK_RED, DKR_RED, RED, LGR_RED, LG_RED};
	pals[8] = (t_palette){V_DK_CYAN, DK_CYAN, DKR_CYAN, CYAN, LGR_CYAN,
		LG_CYAN};
	pals[9] = (t_palette){V_DK_MAGENTA, DK_MAGENTA, DKR_MAGENTA, MAGENTA,
		LGR_MAGENTA, LG_MAGENTA};
	pals[10] = (t_palette){V_DK_GREEN, DK_GREEN, DKR_GREEN, GREEN, LGR_GREEN,
		LG_GREEN};
	pals[11] = (t_palette){V_DK_YELLOW, DK_YELLOW, DKR_YELLOW, YELLOW,
		LGR_YELLOW, LG_YELLOW};
	pals[12] = (t_palette){V_DK_BLUE, DK_BLUE, DKR_BLUE, BLUE, LGR_BLUE,
		LG_BLUE};
}

int	get_color(double max_iter, double iter)
{
	t_dir		*dir;
	t_palette	pals[13];

	dir = g_dr(1);
	inti_pal(pals);
	if (dir->palette < 107)
		return (color_picker(max_iter, iter, pals[dir->palette]));
	else
		return (color_picker(max_iter, iter, pals[dir->palette - 665]));
}
