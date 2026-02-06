
// LayoutPoint.h : Defines point position for control or layout
//

#pragma once
#include "Layouts.h"

namespace Layouts
{

	class LAYOUTS_API CPoint
	{
		int m_iTop;
		int m_iLeft;

	public:
		CPoint();
		CPoint(const CPoint& Point);
		CPoint(int iLeft, int iTop);

		int Top() const;
		int Left() const;

		void SetLeft(int iLeft);
		void SetTop(int iTop);
		
		void SetPoint(const CPoint& Point);
		void SetPoint(int iLeft, int iTop);
	};

}