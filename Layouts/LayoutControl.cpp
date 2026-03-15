
/**
 * \file LayoutControl.cpp
 * \~english @brief File for control layout
 * \~english @details
 * This file contains implementation of classes and tools for control layout
 * \~russian @brief Файл для размещения контрола
 * \~russian @details
 * Этот файл содержит реализацию для размещения контрола
 * \see LayoutItem.cpp
 */

#include "pch.h"
#include "LayoutControl.h"
#include "LayoutPoint.h"
#include "LayoutSize.h"

namespace Layouts
{
	CLayoutMargins CLayoutControl::m_DefaultMargins(0, 0, 0, 0);

	CLayoutControl::CLayoutControl()
	{
		m_Margins = m_DefaultMargins;
		
		m_eHorizontalPolicy = Preferred;
		m_eVerticalPolicy = Preferred;
		
		m_pLayoutItem = 0;
	}

	CLayoutControl::CLayoutControl(LayoutPolicy eHorizontalPolicy, LayoutPolicy eVerticalPolicy)
	{
		m_Margins = m_DefaultMargins;

		m_eHorizontalPolicy = eHorizontalPolicy;
		m_eVerticalPolicy = eVerticalPolicy;

		m_pLayoutItem = 0;
	}

	CLayoutControl::~CLayoutControl()
	{
		delete m_pLayoutItem;
		m_pLayoutItem = 0;
	}

	LayoutPolicy CLayoutControl::HorizontalPolicy()
	{
		return m_eHorizontalPolicy;
	}

	LayoutPolicy CLayoutControl::VerticalPolicy()
	{
		return m_eVerticalPolicy;
	}

	void CLayoutControl::SetPolicy(LayoutPolicy eHorizontalPolicy, LayoutPolicy eVerticalPolicy)
	{
		m_eHorizontalPolicy = eHorizontalPolicy;
		m_eVerticalPolicy = eVerticalPolicy;
	}

	bool CLayoutControl::IsVisible()
	{
		return false;
	}

	void CLayoutControl::Lay(const CLayoutRectangle& Rectangle)
	{
		CLayoutRectangle rectItem(Rectangle);
		if (m_pLayoutItem != nullptr)
		{
			rectItem.RemoveMargins(m_Margins);
			m_pLayoutItem->Lay(rectItem);
		}
	}

	CLayoutSize CLayoutControl::GetMinimal()
	{
		CLayoutSize sizeLayout;
		if (m_pLayoutItem != nullptr)
		{
			sizeLayout = m_pLayoutItem->GetMinimal();
			sizeLayout.AddMargins(m_Margins);
		}

		return sizeLayout;
	}

	CLayoutItem* CLayoutControl::Layout() const
	{
		return m_pLayoutItem;
	}

	void CLayoutControl::SetLayout(CLayoutItem* pLayoutItem)
	{
		m_pLayoutItem = pLayoutItem;
	}

	CLayoutMargins CLayoutControl::GetMargins() const
	{
		return m_Margins;
	}

	void CLayoutControl::SetMargins(int iMargin)
	{
		m_Margins.SetMargins(iMargin);
	}

	void CLayoutControl::SetMargins(int iLeft, int iTop, int iRight, int iBottom)
	{
		m_Margins.SetMargins(iLeft, iTop, iRight, iBottom);
	}

	void CLayoutControl::SetMargins(const CLayoutMargins& Margins)
	{
		m_Margins.SetMargins(Margins);
	}

	void CLayoutControl::SetDefaultMargins(int iMargin)
	{
		m_DefaultMargins.SetMargins(iMargin);
	}

	void CLayoutControl::SetDefaultMargins(int iLeft, int iTop, int iRight, int iBottom)
	{
		m_DefaultMargins.SetMargins(iLeft, iTop, iRight, iBottom);
	}

	void CLayoutControl::SetDefaultMargins(const CLayoutMargins& Margins)
	{
		m_DefaultMargins.SetMargins(Margins);
	}

}