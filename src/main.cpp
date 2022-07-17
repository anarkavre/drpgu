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

#include "DoomRPGUtilOptions.h"

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

int main(int argc, char *argv[])
{
	DoomRPGUtilOption option;

	if (!strcasecmp(argv[1], "-viewmap"))
		option = DoomRPGUtilOption::ViewMap;
	else if (!strcasecmp(argv[1], "-viewmapex"))
		option = DoomRPGUtilOption::ViewMapEx;
	else if (!strcasecmp(argv[1], "-viewgraphics"))
		option = DoomRPGUtilOption::ViewGraphics;
	else if (!strcasecmp(argv[1], "-exportgraphics"))
		option = DoomRPGUtilOption::ExportGraphics;
	else if (!strcasecmp(argv[1], "-exportmappings"))
		option = DoomRPGUtilOption::ExportMappings;
	else if (!strcasecmp(argv[1], "-exportentities"))
		option = DoomRPGUtilOption::ExportEntities;
	else if (!strcasecmp(argv[1], "-exportentitiesex"))
		option = DoomRPGUtilOption::ExportEntitiesEx;

	if (option == DoomRPGUtilOption::ViewMap)
		ViewMap(argc, argv);
	else if (option == DoomRPGUtilOption::ViewMapEx)
		ViewMapEx(argc, argv);
	else if (option == DoomRPGUtilOption::ViewGraphics)
		ViewGraphics(argc, argv);
	else if (option == DoomRPGUtilOption::ExportGraphics)
		ExportGraphics(argc, argv);
	else if (option == DoomRPGUtilOption::ExportMappings)
		ExportMappings(argc, argv);
	else if (option == DoomRPGUtilOption::ExportEntities)
		ExportEntities(argc, argv);
	else if (option == DoomRPGUtilOption::ExportEntitiesEx)
		ExportEntitiesEx(argc, argv);

	return 0;
}