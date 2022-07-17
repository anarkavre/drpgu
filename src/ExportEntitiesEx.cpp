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
#include <fstream>

#include "doomrpg_data.h"

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

void ExportEntitiesEx(int argc, char *argv[])
{
	entitiesex_t *entities = NULL;

	if (!strcasecmp(argv[2], "-entities"))
		entities = LoadEntitiesEx(argv[3]);

	std::ofstream ofstream;

	ofstream.open("entities.txt");

	for (unsigned int i = 0; i < entities->entityCount; i++)
	{
		entityex_t *entity = &entities->entities[i];

		ofstream << "id: " << static_cast<unsigned int>(entity->id) << " ";
		ofstream << "type: " << static_cast<unsigned int>(entity->type) << " ";
		ofstream << "parameter1: " << static_cast<unsigned int>(entity->parameter1) << " ";
		ofstream << "parameter2: " << static_cast<unsigned int>(entity->parameter2) << " ";
		ofstream << "name: " << entity->name << std::endl;
	}

	ofstream.close();

	FreeEntitiesEx(entities);
}