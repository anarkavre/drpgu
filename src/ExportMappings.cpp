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

void ExportMappings(int argc, char *argv[])
{
	mappings_t *mappings = NULL;

	if (!strcasecmp(argv[2], "-mappings"))
		mappings = LoadMappings(argv[3]);

	std::ofstream ofstream;

	ofstream.open("textureMappings.txt");

	for (unsigned int i = 0; i < mappings->textureMappingCount; i++)
	{
		texturemapping_t *textureMapping = &mappings->textureMappings[i];

		ofstream << "mapping: " << i << " ";
		ofstream << "texture: " << static_cast<unsigned int>(textureMapping->texture) << " ";
		ofstream << "palette: " << static_cast<unsigned int>(textureMapping->palette) << std::endl;
	}

	ofstream.close();

	ofstream.open("spriteMappings.txt");

	for (unsigned int i = 0; i < mappings->spriteMappingCount; i++)
	{
		spritemapping_t *spriteMapping = &mappings->spriteMappings[i];

		ofstream << "mapping: " << i << " ";
		ofstream << "sprite: " << static_cast<unsigned int>(spriteMapping->sprite) << " ";
		ofstream << "palette: " << static_cast<unsigned int>(spriteMapping->palette) << std::endl;
	}

	ofstream.close();

	ofstream.open("wallMappings.txt");

	for (unsigned int i = 0; i < mappings->wallMappingCount; i++)
	{
		ofstream << "id: " << i << " ";
		ofstream << "mapping: " << static_cast<unsigned int>(mappings->wallMappings[i]) << std::endl;
	}

	ofstream.close();

	ofstream.open("thingMappings.txt");

	for (unsigned int i = 0; i < mappings->thingMappingCount; i++)
	{
		ofstream << "id: " << i << " ";
		ofstream << "mapping: " << static_cast<unsigned int>(mappings->thingMappings[i]) << std::endl;
	}

	ofstream.close();

	FreeMappings(mappings);
}