set(SOURCE_FILES
	doomrpg_data.c		doomrpg_data.h
				doomrpg_entities.h
	doomrpg_graphics.c	doomrpg_graphics.h
				doomrpg_sounds.h
				DoomRPGUtilOptions.h
	ExportEntities.cpp
	ExportEntitiesEx.cpp
	ExportGraphics.cpp
	ExportMappings.cpp
	main.cpp
	ViewGraphics.cpp
	ViewMap.cpp
	ViewMapEx.cpp
				ViewMapOptions.h)

add_executable(drpgu ${SOURCE_FILES})
target_link_libraries(drpgu ${SDL2_LIBRARIES})