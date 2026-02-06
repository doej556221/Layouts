
// LayoutItem.h : Defines margins of control in layout
//

#pragma once
#include "Layouts.h"

namespace Layouts
{

	class LAYOUTS_API CMargins
	{
		int m_iTop;
		int m_iLeft;
		int m_iBottom;
		int m_iRight;

	public:
		CMargins();
		CMargins(const CMargins& Margins);
		CMargins(int iTop, int iLeft, int iBottom, int iRight);

		int Top() const;
		int Left() const;
		int Bottom() const;
		int Right() const;

		void SetLeft(int iLeft);
		void SetTop(int iTop);
		void SetRight(int iRight);
		void SetBottom(int iBottom);

		void SetMargins(const CMargins& Margins);
		void SetMargins(int iMargin);
		void SetMargins(int iLeft, int iTop, int iRight, int iBottom);
	};

}