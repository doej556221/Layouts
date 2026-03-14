
// LabelAdapter.h: Defines MFC Label Control based on LayoutControl class
//

#include "pch.h"
#include "LabelAdapter.h"

namespace Layouts
{

	CLabelAdapter::CLabelAdapter(CWnd* pWnd)
		: CControlAdapter(pWnd)
	{
		if (::IsWindow(pWnd->GetSafeHwnd()) == FALSE)
			return;

		CDC* pDC = pWnd->GetDC();
		if (pDC == 0) return;

		CString strText;
		pWnd->GetWindowText(strText);

		CSize sizeText = pDC->GetTextExtent(strText);
		m_MinimalSize.SetSize(sizeText.cx, sizeText.cy);
	}

	CLabelAdapter::CLabelAdapter(CWnd* pWnd, LayoutPolicy eHorizontal, LayoutPolicy eVertical)
		: CControlAdapter(pWnd, eHorizontal, eVertical)
	{
		if (::IsWindow(pWnd->GetSafeHwnd()) == FALSE)
			return;

		CDC* pDC = pWnd->GetDC();
		if (pDC == 0)
		{
			m_MinimalSize = m_FixedSize;
			return;
		}

		CString strText;
		pWnd->GetWindowText(strText);

		CSize sizeText = pDC->GetTextExtent(strText);
		m_MinimalSize.SetSize(sizeText.cx, sizeText.cy);
	}

	CLabelAdapter::~CLabelAdapter()
	{

	}

	CLayoutSize CLabelAdapter::GetMinimal()
	{
		CLayoutSize sizeMinimal = m_FixedSize;

		if (m_eHorizontalPolicy == Layouts::Minimal)
			sizeMinimal.SetWidth(m_MinimalSize.Width());

		if (m_eVerticalPolicy == Layouts::Minimal)
			sizeMinimal.SetHeight(m_MinimalSize.Height());

		return sizeMinimal;
	}
}