
// Layouts.h : Defines supplementary structures and classes to use with controls or layouts
//

#pragma once

// Exports
#ifdef LAYOUTS_EXPORTS
#define LAYOUTS_API __declspec(dllexport)
#else
#define LAYOUTS_API __declspec(dllimport)
#endif

class LAYOUTS_API CLayouts {
public:
	CLayouts(void);
};

extern LAYOUTS_API int nLayouts;
LAYOUTS_API int fnLayouts(void);

namespace Layouts
{

	enum Orientation
	{
		Horizontal,
		Vertical
	};

	enum LayoutPolicy
	{
		Fixed,
		Minimal,
		Stretched,
		Preferred
	};
}