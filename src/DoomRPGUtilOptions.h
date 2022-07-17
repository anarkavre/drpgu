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

#ifndef __DOOMRPGUTILOPTIONS_H__
#define __DOOMRPGUTILOPTIONS_H__

enum class DoomRPGUtilOption
{
	ViewMap,
	ViewMapEx,
	ViewGraphics,
	ExportGraphics,
	ExportMappings,
	ExportEntities,
	ExportEntitiesEx,
};

void ViewMap(int argc, char *argv[]);
void ViewMapEx(int argc, char *argv[]);
void ViewGraphics(int argc, char *argv[]);
void ExportGraphics(int argc, char *argv[]);
void ExportMappings(int argc, char *argv[]);
void ExportEntities(int argc, char *argv[]);
void ExportEntitiesEx(int argc, char *argv[]);

#endif