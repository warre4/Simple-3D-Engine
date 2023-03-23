#include "color.h"

void SetColorRGBA(Color* pColor, uint32_t rgbaHexCode)
{
	pColor->r = rgbaHexCode >> (8 * 3);
	pColor->g = 0x00FF0000 | rgbaHexCode >> (8 * 2);
	pColor->b = 0x0000FF00 | rgbaHexCode >> (8 * 1);
	pColor->a = 0x000000FF;
}
void SetColorRGB(Color* pColor, uint32_t rgbHexCode)
{
	SetColorRGBA(pColor, RGB_A_TO_RGBA(rgbHexCode, pColor->a));
}
