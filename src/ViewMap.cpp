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

#include <bitset>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

#include "SDL.h"

#include "ViewMapOptions.h"
#include "doomrpg_data.h"

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

void ViewMap(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("drpgu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 256, 256, 0);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	bspmap_t *map = NULL;

	if (!strcasecmp(argv[2], "-map"))
		map = LoadBspMap(argv[3]);

	bool running = true;

	ViewMapOptions viewMapOptions = ViewMapOptions::Lines;

	SDL_Point clickedPoint;
	int clickedIndices[2] = { -1, -1 };

	std::default_random_engine generator;
	std::uniform_int_distribution<unsigned int> distribution(0, 255);

	std::vector<SDL_Color> colors;

	for (unsigned int i = 0; i < map->nodeCount; i++)
	{
		bspnode_t *node = &map->nodes[i];

		if (node->nodeType == 0)
		{
			SDL_Color color;
			color.r = distribution(generator);
			color.g = distribution(generator);
			color.b = distribution(generator);
			color.a = 255;
			colors.push_back(color);
		}
	}

	while (running)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;

			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			{
				clickedPoint.x = event.button.x;
				clickedPoint.y = event.button.y;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_1:
					viewMapOptions ^= ViewMapOptions::Lines;
					break;
				case SDLK_2:
					viewMapOptions ^= ViewMapOptions::Things;
					break;
				case SDLK_3:
					viewMapOptions ^= ViewMapOptions::Events;
					break;
				case SDLK_4:
					viewMapOptions ^= ViewMapOptions::BoundingBoxes;
					break;
				case SDLK_5:
					viewMapOptions ^= ViewMapOptions::BlockMap;
					break;
				default:
					break;
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		if ((viewMapOptions & ViewMapOptions::BlockMap) == ViewMapOptions::BlockMap)
		{
			for (unsigned int y = 0; y < 32; y++)
			{
				for (unsigned int x = 0; x < 32; x++)
				{
					SDL_Rect rect = { x * 8 + 1, y * 8 + 1, 7, 7 };

					unsigned char block = (map->blockMap[y * 8 + (x / 4)] >> ((x % 4) * 2)) & 0x3;
					unsigned char color = 192 * block / 3;

					SDL_SetRenderDrawColor(renderer, color, color, color, 255);
					SDL_RenderFillRect(renderer, &rect);
				}
			}
		}

		if ((viewMapOptions & ViewMapOptions::BoundingBoxes) == ViewMapOptions::BoundingBoxes)
		{
			unsigned int j = 0;

			for (unsigned int i = 0; i < map->nodeCount; i++)
			{
				bspnode_t *node = &map->nodes[i];

				if (node->nodeType == 0)
				{
					int x = node->boundingBoxMin.x;
					int y = node->boundingBoxMin.y;
					int w = node->boundingBoxMax.x - node->boundingBoxMin.x + 1;
					int h = node->boundingBoxMax.y - node->boundingBoxMin.y + 1;

					SDL_Rect rect = { x, y, w, h };

					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
					SDL_RenderDrawRect(renderer, &rect);

					rect.x += 1;
					rect.y += 1;
					rect.w -= 2;
					rect.h -= 2;

					SDL_Color &color = colors[j++];

					SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
					SDL_RenderFillRect(renderer, &rect);
				}
			}
		}

		if ((viewMapOptions & ViewMapOptions::Events) == ViewMapOptions::Events)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

			unsigned int clickedBlockX = clickedPoint.x / 8;
			unsigned int clickedBlockY = clickedPoint.y / 8;

			for (unsigned int i = 0; i < map->eventCount; i++)
			{
				uint32_t *event = &map->events[i];

				unsigned int blockX = *event & 0x1F;
				unsigned int blockY = (*event >> 5) & 0x1F;

				SDL_Rect rect = { blockX * 8 + 1, blockY * 8 + 1, 7, 7 };

				SDL_RenderFillRect(renderer, &rect);

				if (clickedBlockX == blockX && clickedBlockY == blockY)
					clickedIndices[1] = i;
			}
		}

		if ((viewMapOptions & ViewMapOptions::Lines) == ViewMapOptions::Lines)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			for (unsigned int i = 0; i < map->lineCount; i++)
			{
				linesegment_t *line = &map->lines[i];

				SDL_RenderDrawLine(renderer, line->start.x, line->start.y, line->end.x, line->end.y);
			}
		}

		if ((viewMapOptions & ViewMapOptions::Things) == ViewMapOptions::Things)
		{
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

			for (unsigned int i = 0; i < map->thingCount; i++)
			{
				thing_t *thing = &map->things[i];

				SDL_Rect rect = { thing->position.x - 1, thing->position.y - 1, 3, 3 };

				SDL_RenderFillRect(renderer, &rect);

				if (clickedPoint.x >= thing->position.x - 1 && clickedPoint.x <= thing->position.x + 1 && clickedPoint.y >= thing->position.y - 1 && clickedPoint.y <= thing->position.y + 1)
					clickedIndices[0] = i;
			}
		}
		
		SDL_RenderPresent(renderer);

		if (clickedIndices[0] != -1)
		{
			thing_t *thing = &map->things[clickedIndices[0]];

			std::cout << "positionX: " << static_cast<unsigned int>(thing->position.x) << " ";
			std::cout << "positionY: " << static_cast<unsigned int>(thing->position.y) << std::endl;

			std::cout << "id: " << std::setw(2) << static_cast<unsigned int>(thing->id) << " ";
			std::cout << "flags: " << std::bitset<16>(thing->flags) << std::endl << std::endl;
		}
		else if (clickedIndices[1] != -1)
		{
			uint32_t *event = &map->events[clickedIndices[1]];

			unsigned int blockX = *event & 0x1F;
			unsigned int blockY = (*event >> 5) & 0x1F;

			std::cout << "blockX: " << blockX << " ";
			std::cout << "blockY: " << blockY << std::endl;

			unsigned int commandStart = (*event >> 10) & 0x1FF;
			unsigned int commandCount = (*event >> 19) & 0x3F;

			for (unsigned int j = 0; j < commandCount; j++)
			{
				command_t *cmd = &map->commands[commandStart + j];

				std::cout << "id: " << std::setw(2) << unsigned int(cmd->id) << " ";
				std::cout << "arg1: " << std::bitset<32>(cmd->argument1) << " ";
				std::cout << "arg2: " << std::bitset<32>(cmd->argument2) << std::endl;
			}

			std::cout << std::endl;
		}

		clickedIndices[0] = -1;
		clickedIndices[1] = -1;
		clickedPoint.x = -1;
		clickedPoint.y = -1;
	}

	FreeBspMap(map);

	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);

	SDL_Quit();
}