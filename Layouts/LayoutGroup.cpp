
// LayoutsGroup.cpp : Defines a group of controls or inner layouts
//

#include "pch.h"
#include "LayoutGroup.h"

#include "LayoutPoint.h"
#include "LayoutSize.h"
#include "LayoutRect.h"
#include "LayoutMargins.h"
#include "LayoutItem.h"
#include "LayoutControl.h"

#include <map>

namespace Layouts
{

	CLayoutGroup::CLayoutGroup()
	{
		m_eOrientation = Horizontal;
	};

	CLayoutGroup::CLayoutGroup(Orientation eOrientation) 
	{ 
		m_eOrientation = eOrientation; 
	};
	
	CLayoutGroup::~CLayoutGroup()
	{
		for (auto pItem : m_arrItems)
			delete pItem;

		m_arrItems.clear();
	}

	void CLayoutGroup::AddItem(CLayoutControl* pControl)
	{
		m_arrItems.push_back(pControl);
	}

	void CLayoutGroup::RemoveItem(CLayoutControl* pControl)
	{
		m_arrItems.remove(pControl);
	}

	void CLayoutGroup::AddItem(CLayoutItem* pItem)
	{
		CLayoutControl* pLayoutControl = new CLayoutControl();
		pLayoutControl->SetPolicy(Preferred, Preferred);
		pLayoutControl->SetLayout(pItem);

		m_arrItems.push_back(pLayoutControl);
	}

	int CLayoutGroup::CountItems()
	{
		return m_arrItems.size();
	}

	void CLayoutGroup::Lay(const CRectangle& Rectangle)
	{
		if (m_arrItems.empty() == true)
			return;
		
		CRectangle rectLayout(Rectangle);

		if (m_eOrientation == Horizontal)
		{
			int iPosition = rectLayout.Left();
			int iSpacing = m_iSpacing * (m_arrItems.size() - 1);
			int iPortion = (rectLayout.Width() - iSpacing) / (m_arrItems.size() - 1);
			
			int iFixedWidth = 0;
			int iFixedCount = 0;
			int iFixedPortion = 0;

			int iStretchedWidth = 0;
			int iStretchedCount = 0;
			int iStretchedPortion = 0;

			for (auto pItem : m_arrItems)
			{
				CSize sizeMinimal = pItem->GetMinimal();

				if (pItem->HorizontalPolicy() == Fixed)
				{
					iFixedWidth += sizeMinimal.Width();
					iFixedCount++;
				}
				else if (pItem->HorizontalPolicy() == Stretched)
				{
					iStretchedWidth = sizeMinimal.Width();
					iStretchedCount++;
				}
			}

			// if (iFixedCount > 0)
			// iFixedPortion

			if (iStretchedCount > 0)
				iStretchedPortion = (rectLayout.Width() - iFixedWidth - iSpacing * (m_arrItems.size() - 1)) / iStretchedCount;

			for (auto pItem : m_arrItems)
			{
				CSize sizeMinimal = pItem->GetMinimal();

				CRectangle rectItem;
				// rectItem.SetRectangle(iPosition, rectLayout.Top(), iPosition + iPortion, rectLayout.Bottom());
				rectItem.SetRectangle(iPosition, rectLayout.Top(), iPosition + sizeMinimal.Width(), rectLayout.Bottom());

				if (pItem->HorizontalPolicy() == Stretched)
					rectItem.SetRight(rectItem.Left() + iStretchedPortion);

				pItem->Lay(rectItem);

				iPosition = rectItem.Right() + m_iSpacing;
			}
		}
		else if (m_eOrientation == Vertical)
		{
			int iPosition = rectLayout.Top();

			int iSpacing = m_iSpacing * (m_arrItems.size() - 1);
			int iPortion = (rectLayout.Height() - iSpacing) / m_arrItems.size();

			for (auto pItem : m_arrItems)
			{
				CSize sizeMinimal = pItem->GetMinimal();

				CRectangle rectItem;
				// rectItem.SetRectangle(rectLayout.Left(), iPosition, rectLayout.Right(), iPosition + iPortion);
				rectItem.SetRectangle(rectLayout.Left(), iPosition, rectLayout.Right(), iPosition + sizeMinimal.Height());

				pItem->Lay(rectItem);

				iPosition = rectItem.Bottom() + m_iSpacing;
			}
		}

	}

	CSize CLayoutGroup::GetMinimal()
	{
		CSize sizeMinimal;

		for (auto pItem : m_arrItems)
		{
			if (m_eOrientation == Horizontal)
			{
				CSize sizeItem = pItem->GetMinimal();
				sizeMinimal.SetWidth(sizeMinimal.Width() + sizeItem.Width());
				
				if (sizeMinimal.Height() < sizeItem.Height())
					sizeMinimal.SetHeight(sizeItem.Height());
			}
			else if (m_eOrientation == Vertical)
			{
				CSize sizeItem = pItem->GetMinimal();
				sizeMinimal.SetHeight(sizeMinimal.Height() + sizeItem.Height());

				if (sizeMinimal.Width() < sizeItem.Width())
					sizeMinimal.SetWidth(sizeItem.Width());
			}
		}

		int iSpacing = m_iSpacing * (m_arrItems.size() - 1);
		if (m_eOrientation == Horizontal) sizeMinimal.SetWidth(sizeMinimal.Width() + iSpacing);
		if (m_eOrientation == Vertical) sizeMinimal.SetHeight(sizeMinimal.Height() + iSpacing);

		return sizeMinimal;
	}

	void CLayoutGroup::SetOrientation(Orientation Value)
	{
		m_eOrientation = Value;
	}
}