
// LayoutRect.h : Defines rectagular area for control or layout
//

#pragma once
#include "Layouts.h"
#include "LayoutPoint.h"

namespace Layouts
{
	class CPoint;
	class CSize;
	class CMargins;

	class LAYOUTS_API CRectangle
	{
		int m_iLeft;
		int m_iTop;
		int m_iRight;
		int m_iBottom;

	public:
		CRectangle();
		CRectangle(const CRectangle& Rectangle);
		CRectangle(int iLeft, int iTop, int iRight, int iBottom);
		CRectangle(const CPoint& Point, const CSize& Size);

		int Left() const;
		int Top() const;
		int Right() const;
		int Bottom() const;
		int Width() const;
		int Height() const;

		void SetLeft(int iLeft);
		void SetTop(int iTop);
		void SetRight(int iRight);
		void SetBottom(int iBottom);
				
		CPoint Point() const;
		void SetPoint(int iLeft, int iTop);
		void SetPoint(const CPoint& Point);

		CSize Size() const;
		void SetSize(int iWidth, int iHeight);
		void SetSize(const CSize& Size);
		void SetWidth(int iWidth);
		void SetHeight(int iHeight);

		void SetRectangle(const CRectangle& Rectangle);
		void SetRectangle(const CPoint& Point, const CSize& Size);
		void SetRectangle(int iLeft, int iTop, int iRight, int iBottom);

		void AddMargins(const CMargins& Margins);
		void AddMargins(int iMargins);
		void RemoveMargins(const CMargins& Margins);
		void RemoveMargins(int iMargins);
	};

}