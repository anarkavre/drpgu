// drpgu
// Copyright(C) 2020-2022 John D. Corrado
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

#include <cstring>

#include "SDL.h"

#include "doomrpg_data.h"
#include "doomrpg_graphics.h"

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

void ViewGraphics(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("drpgu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 256, 256, 0);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	mappings_t *mappings = NULL;
	uint8_t *wallTexels = NULL;
	uint8_t *bitShapes = NULL;
	uint8_t *spriteTexels = NULL;
	uint16_t *palettes = NULL;

	for (int i = 2; i < argc; i++)
	{
		if (!strcasecmp(argv[i], "-mappings"))
			mappings = LoadMappings(argv[i + 1]);
		else if (!strcasecmp(argv[i], "-wtexels"))
			wallTexels = LoadTexels(argv[i + 1]);
		else if (!strcasecmp(argv[i], "-bitshapes"))
			bitShapes = LoadBitShapes(argv[i + 1]);
		else if (!strcasecmp(argv[i], "-stexels"))
			spriteTexels = LoadTexels(argv[i + 1]);
		else if (!strcasecmp(argv[i], "-palettes"))
			palettes = LoadPalettes(argv[i + 1]);
	}

	uint32_t *image[2] = { NULL, NULL };

	SDL_Surface *surface[2] = { NULL, NULL };

	SDL_Texture *texture[2] = { NULL, NULL };

	int32_t columnCount[2];

	int32_t cellCount[2];

	if (mappings != NULL && wallTexels != NULL && palettes != NULL)
	{
		uint32_t imageWidth;
		uint32_t imageHeight;

		image[0] = CreateRGBAImageFromWallTextures(mappings->textureMappings, mappings->textureMappingCount, wallTexels, palettes, &imageWidth, &imageHeight);

		surface[0] = SDL_CreateRGBSurfaceWithFormatFrom(image[0], imageWidth, imageHeight, 32, imageWidth * sizeof(uint32_t), SDL_PIXELFORMAT_RGBA32);

		texture[0] = SDL_CreateTextureFromSurface(renderer, surface[0]);

		columnCount[0] = surface[0]->w / 64;

		cellCount[0] = (int32_t)mappings->textureMappingCount;
	}

	if (mappings != NULL && bitShapes != NULL && spriteTexels != NULL && palettes != NULL)
	{
		uint32_t imageWidth;
		uint32_t imageHeight;

		image[1] = CreateRGBAImageFromSprites(mappings->spriteMappings, mappings->spriteMappingCount, bitShapes, spriteTexels, palettes, &imageWidth, &imageHeight);

		surface[1] = SDL_CreateRGBSurfaceWithFormatFrom(image[1], imageWidth, imageHeight, 32, imageWidth * sizeof(uint32_t), SDL_PIXELFORMAT_RGBA32);

		texture[1] = SDL_CreateTextureFromSurface(renderer, surface[1]);

		columnCount[1] = surface[1]->w / 64;

		cellCount[1] = (int32_t)mappings->spriteMappingCount;
	}

	FreeMappings(mappings);
	FreeTexels(wallTexels);
	FreeBitShapes(bitShapes);
	FreeTexels(spriteTexels);
	FreePalettes(palettes);

	int32_t cell = 0;
	uint32_t index = (texture[0] != NULL ? 0 : 1);

	SDL_Rect srcrect = { 0, 0, 64, 64 };
	SDL_Rect dstrect = { 96, 96, 64, 64 };

	bool keyPressed = false;

	bool running = true;

	while (running)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;
			
			if (event.type == SDL_KEYDOWN)
			{
				if (!keyPressed)
				{
					if (event.key.keysym.sym == SDLK_LEFT)
					{
						cell--;

						if (cell < 0)
							cell = cellCount[index] - 1;

						srcrect.x = (cell % columnCount[index]) * 64;
						srcrect.y = (cell / columnCount[index]) * 64;
					}
					else if (event.key.keysym.sym == SDLK_RIGHT) {
						cell++;

						if (cell > cellCount[index] - 1)
							cell = 0;

						srcrect.x = (cell % columnCount[index]) * 64;
						srcrect.y = (cell / columnCount[index]) * 64;
					}
					else if (event.key.keysym.sym == SDLK_RETURN && texture[!index] != NULL)
					{
						index = !index;
						cell = 0;
						srcrect = { 0, 0, 64, 64 };
					}

					keyPressed = true;
				}

				if (event.key.keysym.mod & KMOD_CTRL && event.key.keysym.sym == SDLK_s)
				{
					SDL_Surface *temp = SDL_CreateRGBSurfaceWithFormat(0, 64, 64, 32, SDL_PIXELFORMAT_RGBA32);
					SDL_BlitSurface(surface[index], &srcrect, temp, NULL);
					char filename[8];
					SDL_itoa(cell, filename, 10);
					SDL_strlcat(filename, ".bmp", 10);
					SDL_SaveBMP(temp, filename);
					SDL_FreeSurface(temp);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				keyPressed = false;
			}
		}
		
		SDL_RenderFillRect(renderer, &dstrect);
		SDL_RenderCopy(renderer, texture[index], &srcrect, &dstrect);
		SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyTexture(texture[0]);
	SDL_DestroyTexture(texture[1]);
	
	SDL_FreeSurface(surface[0]);
	SDL_FreeSurface(surface[1]);
	
	free(image[0]);
	free(image[1]);

	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);

	SDL_Quit();
}