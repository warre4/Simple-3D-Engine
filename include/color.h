#pragma once
#include "general.h"

typedef v4ui8 Color;

enum HexCode
{
	Yellow = 0xFFFF00,
	YellowDark = 0xA0A000,
	Green = 0x00FF00,
	GreenDark = 0x00A000,
	Cyan = 0x00FFFF,
	CyanDark = 0x00A0A0,
	Brown = 0xA06400,
	BrownDark = 0x6E3200,

	DefaultBlue = 0x003C82
};

#define RGB_A_TO_RGBA(rgb, a)						(rgb << 8) | a
#define RGBA_TO_RGB(rgba)							(uint32_t)rgba >> 8

// ---------------
// -- Functions --
// ---------------

void SetColorRGBA(Color* pColor, uint32_t rgbaHexCode);
void SetColorRGB(Color* pColor, uint32_t rgbHexCode);