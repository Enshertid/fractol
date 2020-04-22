/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:32:10 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/22 16:04:03 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <string.h>
#include <stdint.h>

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("OMG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	SDL_Surface *surface = SDL_GetWindowSurface(window);
	int32_t *pixels = surface->pixels;
	memset(pixels, 0, WIDTH * HEIGHT * 4);
	int quit = 0;
	int left_button = 0;
	SDL_Event event;
	while (!quit)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_MOUSEBUTTONDOWN :
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					left_button = 1;
					int x = event.button.x;
					int y = event.button.y;
					pixels[y * WIDTH + x] = 0xFFFFFF;
				}
				break;
			}
			case SDL_MOUSEBUTTONUP :
			{
				if (event.button.button == SDL_BUTTON_LEFT)
					left_button = 0;
				break;
			}
			case SDL_KEYDOWN :
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					quit = 1;
				break;
			}
			case SDL_QUIT :
			{
				quit = 1;
				break;
			}
			case SDL_MOUSEMOTION :
			{
				if (left_button)
				{
					int x = event.button.x;
					int y = event.button.y;
					pixels[y * WIDTH + x] = 0xFFFFFF;
				}
				break;
			}
		}
		if (left_button)
			SDL_UpdateWindowSurface(window);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
