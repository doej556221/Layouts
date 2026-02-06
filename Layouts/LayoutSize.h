
// LayoutSize.h : Defines size for control or layout
//

#pragma once
#include "Layouts.h"

namespace Layouts
{
	class CMargins;

	class LAYOUTS_API CSize
	{
		int m_iWidth;
		int m_iHeight;

	public:
		CSize();
		CSize(const CSize& Size);
		CSize(int iWidth, int iHeight);

		int Width() const;
		int Height() const;
		
		void SetWidth(int iWidth);
		void SetHeight(int iHeight);
		
		void SetSize(const CSize& Size);
		void SetSize(int iWidth, int iHeight);

		void AddMargins(const CMargins& Margins);
		void RemoveMargins(const CMargins& Margins);
	};

}