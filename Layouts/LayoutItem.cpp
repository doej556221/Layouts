
// LayoutsItem.cpp : Defines an abstract layout item inherit by controls or layouts
//

#include "pch.h"
#include "Layouts.h"
#include "LayoutItem.h"
#include "LayoutSize.h"
#include "LayoutRect.h"
#include "LayoutMargins.h"

namespace Layouts
{
	int CLayoutItem::m_iDefaultSpacing = 5;
	
	CLayoutItem::CLayoutItem()
	{
		m_iSpacing = m_iDefaultSpacing;
	}

	CLayoutItem::~CLayoutItem()
	{

	}

	void CLayoutItem::Lay(const CRectangle& Rectangle)
	{

	}

	CSize CLayoutItem::GetMinimal()
	{
		CSize Size(0, 0);
		return Size;
	}

	int CLayoutItem::Spacing()
	{
		return m_iSpacing;
	}

	void CLayoutItem::SetDefaultSpacing(int iSpacing)
	{
		m_iDefaultSpacing = iSpacing;
	}

	void CLayoutItem::SetSpacing(int iSpacing)
	{
		m_iSpacing = iSpacing;
	}
}
