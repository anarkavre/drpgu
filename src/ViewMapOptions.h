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

#ifndef __VIEWMAPOPTIONS_H__
#define __VIEWMAPOPTIONS_H__

#include <type_traits>

enum class ViewMapOptions
{
	Lines = 0x1,
	Things = 0x2,
	Events = 0x4,
	BoundingBoxes = 0x8,
	BlockMap = 0x10
};

inline ViewMapOptions operator |(ViewMapOptions a, ViewMapOptions b)
{
	return static_cast<ViewMapOptions>(static_cast<std::underlying_type<ViewMapOptions>::type>(a) | static_cast<std::underlying_type<ViewMapOptions>::type>(b));
}

inline ViewMapOptions operator &(ViewMapOptions a, ViewMapOptions b)
{
	return static_cast<ViewMapOptions>(static_cast<std::underlying_type<ViewMapOptions>::type>(a) & static_cast<std::underlying_type<ViewMapOptions>::type>(b));
}

inline ViewMapOptions operator ^(ViewMapOptions a, ViewMapOptions b)
{
	return static_cast<ViewMapOptions>(static_cast<std::underlying_type<ViewMapOptions>::type>(a) ^ static_cast<std::underlying_type<ViewMapOptions>::type>(b));
}

inline ViewMapOptions operator ~(ViewMapOptions a)
{
	return static_cast<ViewMapOptions>(~static_cast<std::underlying_type<ViewMapOptions>::type>(a));
}

inline ViewMapOptions &operator |=(ViewMapOptions &a, ViewMapOptions b)
{
	return reinterpret_cast<ViewMapOptions &>(reinterpret_cast<std::underlying_type<ViewMapOptions>::type &>(a) |= static_cast<std::underlying_type<ViewMapOptions>::type>(b));
}

inline ViewMapOptions &operator &=(ViewMapOptions &a, ViewMapOptions b)
{
	return reinterpret_cast<ViewMapOptions &>(reinterpret_cast<std::underlying_type<ViewMapOptions>::type &>(a) &= static_cast<std::underlying_type<ViewMapOptions>::type>(b));
}

inline ViewMapOptions &operator ^=(ViewMapOptions &a, ViewMapOptions b)
{
	return reinterpret_cast<ViewMapOptions &>(reinterpret_cast<std::underlying_type<ViewMapOptions>::type &>(a) ^= static_cast<std::underlying_type<ViewMapOptions>::type>(b));
}

#endif
