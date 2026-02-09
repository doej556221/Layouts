
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

		struct CCalculation
		{
			int m_iWidth;
			int m_iHeight;
			int m_iCount;
			int m_iPortion;

			CCalculation()
			{
				m_iWidth = 0;
				m_iHeight = 0;
				m_iCount = 0;
				m_iPortion = 0;
			}
		} 
		calcFixed, calcPreferred, calcStretched;

		if (m_eOrientation == Horizontal)
		{
			int iPosition = rectLayout.Left();
			int iSpacing = m_iSpacing * (m_arrItems.size() - 1);
			int iPortion = (rectLayout.Width() - iSpacing) / (m_arrItems.size() - 1);	

			for (auto pItem : m_arrItems)
			{
				CSize sizeMinimal = pItem->GetMinimal();

				if (pItem->HorizontalPolicy() == Fixed)
				{
					calcFixed.m_iWidth += sizeMinimal.Width();
					calcFixed.m_iCount++;
				}
				else if (pItem->HorizontalPolicy() == Stretched)
				{
					calcStretched.m_iWidth += sizeMinimal.Width();
					calcStretched.m_iCount++;
				}

				if (pItem->VerticalPolicy() == Fixed)
				{
					if (calcFixed.m_iHeight < sizeMinimal.Width())
						calcFixed.m_iHeight = sizeMinimal.Width();
				}
				else if (pItem->VerticalPolicy() == Preferred)
				{
					if (calcPreferred.m_iHeight < sizeMinimal.Width())
						calcPreferred.m_iHeight = sizeMinimal.Width();
				}
				else if (pItem->VerticalPolicy() == Stretched)
				{
					if (calcStretched.m_iHeight < sizeMinimal.Width())
						calcStretched.m_iHeight = sizeMinimal.Width();
				}
			}

			if (calcStretched.m_iCount > 0)
				calcStretched.m_iPortion = (rectLayout.Width() - calcPreferred.m_iWidth - calcFixed.m_iWidth - m_iSpacing * (m_arrItems.size() - 1)) / calcStretched.m_iCount;

			// if (calcPreferred.m_iCount > 0)
			// calcPreferred.m_iPortion

			// if (calcFixed.m_iCount > 0)
			// calcFixed.m_iPortion

			for (auto pItem : m_arrItems)
			{
				CSize sizeMinimal = pItem->GetMinimal();

				CRectangle rectItem;
				rectItem.SetRectangle(iPosition, rectLayout.Top(), iPosition + sizeMinimal.Width(), rectLayout.Bottom());

				if (pItem->HorizontalPolicy() == Stretched)
					rectItem.SetRight(rectItem.Left() + calcStretched.m_iPortion);

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

				if (pItem->HorizontalPolicy() == Fixed)
				{
					if (calcFixed.m_iWidth < sizeMinimal.Width())
						calcFixed.m_iWidth = sizeMinimal.Width();
				}
				else if (pItem->HorizontalPolicy() == Preferred)
				{
					if (calcPreferred.m_iWidth < sizeMinimal.Width())
						calcPreferred.m_iWidth = sizeMinimal.Width();
				}
				else if (pItem->HorizontalPolicy() == Stretched)
				{
					if (calcStretched.m_iWidth < sizeMinimal.Width())
						calcStretched.m_iWidth = sizeMinimal.Width();
				}

				if (pItem->VerticalPolicy() == Fixed)
				{
					calcFixed.m_iHeight += sizeMinimal.Height();
					calcFixed.m_iCount++;
				}
				else if (pItem->VerticalPolicy() == Preferred)
				{
					calcPreferred.m_iHeight += sizeMinimal.Height();
					calcPreferred.m_iCount++;
				}
				else if (pItem->VerticalPolicy() == Stretched)
				{
					calcStretched.m_iHeight += sizeMinimal.Height();
					calcStretched.m_iCount++;
				}
			}

			if (calcStretched.m_iCount > 0)
				calcStretched.m_iPortion = (rectLayout.Height() - calcFixed.m_iHeight - calcPreferred.m_iHeight - m_iSpacing * (m_arrItems.size() - 1)) / calcStretched.m_iCount;

			// if (calcPreferred.m_iCount > 0)
			// calcPreferred.m_iPortion

			// if (calcFixed.m_iCount > 0)
			// calcFixed.m_iPortion

			for (auto pItem : m_arrItems)
			{
				CSize sizeMinimal = pItem->GetMinimal();

				CRectangle rectItem;
				rectItem.SetRectangle(rectLayout.Left(), iPosition, rectLayout.Right(), iPosition + sizeMinimal.Height());

				if (pItem->VerticalPolicy() == Stretched)
					rectItem.SetBottom(rectItem.Top() + calcStretched.m_iPortion);

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