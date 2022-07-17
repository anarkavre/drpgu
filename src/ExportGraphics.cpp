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

void ExportGraphics(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

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

	if (mappings != NULL && wallTexels != NULL && palettes != NULL)
	{
		uint32_t imageWidth;
		uint32_t imageHeight;

		uint32_t *image = CreateRGBAImageFromWallTextures(mappings->textureMappings, mappings->textureMappingCount, wallTexels, palettes, &imageWidth, &imageHeight);

		SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormatFrom(image, imageWidth, imageHeight, 32, imageWidth * sizeof(uint32_t), SDL_PIXELFORMAT_RGBA32);

		SDL_SaveBMP(surface, "textures.bmp");

		SDL_FreeSurface(surface);

		free(image);
	}

	if (mappings != NULL && bitShapes != NULL && spriteTexels != NULL && palettes != NULL)
	{
		uint32_t imageWidth;
		uint32_t imageHeight;

		uint32_t *image = CreateRGBAImageFromSprites(mappings->spriteMappings, mappings->spriteMappingCount, bitShapes, spriteTexels, palettes, &imageWidth, &imageHeight);

		SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormatFrom(image, imageWidth, imageHeight, 32, imageWidth * sizeof(uint32_t), SDL_PIXELFORMAT_RGBA32);

		SDL_SaveBMP(surface, "sprites.bmp");

		SDL_FreeSurface(surface);

		free(image);
	}

	FreeMappings(mappings);
	FreeTexels(wallTexels);
	FreeBitShapes(bitShapes);
	FreeTexels(spriteTexels);
	FreePalettes(palettes);

	SDL_Quit();
}