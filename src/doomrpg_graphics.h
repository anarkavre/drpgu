#ifndef __DOOMRPG_GRAPHICS_H__
#define __DOOMRPG_GRAPHICS_H__

#include "doomrpg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t *CreateRGBAImageFromWallTextures(const texturemapping_t *textureMappings, uint32_t textureMappingCount, const uint8_t *wallTexels, const uint16_t *palettes, uint32_t *imageWidth, uint32_t *imageHeight);
uint32_t *CreateRGBAImageFromSprites(const spritemapping_t *spriteMappings, uint32_t spriteMappingCount, const uint8_t *bitShapes, const uint8_t *spriteTexels, const uint16_t *palettes, uint32_t *imageWidth, uint32_t *imageHeight);

#ifdef __cplusplus
}
#endif

#endif