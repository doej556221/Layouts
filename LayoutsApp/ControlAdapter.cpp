
// Control.h: Defines MFC Control based on LayoutControl class
//


#include "pch.h"
#include "ControlAdapter.h"

#include "LayoutSize.h"
#include "LayoutRect.h"

namespace Layouts
{
	CMap<HWND, HWND, CControlAdapter*, CControlAdapter*> CControlAdapter::m_mapProcedures;

	CControlAdapter::CControlAdapter(CWnd* pWnd)
	{
		m_pWnd = pWnd;

		CRect rectControl;
		if (::IsWindow(m_pWnd->GetSafeHwnd()) == TRUE)
			m_pWnd->GetWindowRect(&rectControl);

		m_FixedSize.SetSize(rectControl.Width(), rectControl.Height());
		m_pOriginalProcedure = 0;
	}

	CControlAdapter::CControlAdapter(CWnd* pWnd, LayoutPolicy eHorizontalPolicy, LayoutPolicy eVerticalPolicy)
		: CLayoutControl(eHorizontalPolicy, eVerticalPolicy)
	{
		m_pWnd = pWnd;

		CRect rectControl;
		if (::IsWindow(m_pWnd->GetSafeHwnd()) == TRUE)
			m_pWnd->GetWindowRect(&rectControl);

		m_FixedSize.SetSize(rectControl.Width(), rectControl.Height());
		m_pOriginalProcedure = 0;
	}

	CControlAdapter::~CControlAdapter()
	{
		if (m_pOriginalProcedure != 0)
		{
			m_mapProcedures.RemoveKey(m_pWnd->GetSafeHwnd());
			if (::IsWindow(m_pWnd->GetSafeHwnd()) == TRUE)
				SetWindowLongPtr(m_pWnd->GetSafeHwnd(), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(m_pOriginalProcedure));
		}
	}

	bool CControlAdapter::IsVisible()
	{
		if (::IsWindow(m_pWnd->GetSafeHwnd()) == TRUE)
		{
			if (m_pWnd->IsWindowVisible() == TRUE)
				return true;

			/* BOOL bVisible = GetWindowLong(m_pWnd->GetSafeHwnd(), GWL_STYLE) & WS_VISIBLE ? TRUE : FALSE;
			if (bVisible == TRUE)
				return true;
				*/
		}

		return false;
	}

	void CControlAdapter::Lay()
	{
		CRect rectClient;
		if (::IsWindow(m_pWnd->GetSafeHwnd()) == TRUE)
			m_pWnd->GetClientRect(&rectClient);

		CRectangle Rectangle(rectClient.left, rectClient.top, rectClient.right, rectClient.bottom);
		Rectangle.RemoveMargins(m_Margins);

		CRectangle rectItem(Rectangle);
		if (m_pLayoutItem != nullptr)
		{
			rectItem.RemoveMargins(m_Margins);
			m_pLayoutItem->Lay(rectItem);
		}

		if (::IsWindow(m_pWnd->GetSafeHwnd()) == TRUE)
			m_pWnd->RedrawWindow();
	}

	void CControlAdapter::Lay(const CRectangle& Rectangle)
	{
		CRect rectControl(Rectangle.Left(), Rectangle.Top(), Rectangle.Right(), Rectangle.Bottom());

		if (m_eHorizontalPolicy == Layouts::Fixed)
			rectControl.right = rectControl.left + m_FixedSize.Width();

		if (m_eVerticalPolicy == Layouts::Fixed)
			rectControl.bottom = rectControl.top + m_FixedSize.Height();

		if (::IsWindow(m_pWnd->GetSafeHwnd()) == TRUE)
			m_pWnd->SetWindowPos(NULL, rectControl.left, rectControl.top, rectControl.Width(), rectControl.Height(), SWP_NOZORDER);

		if (m_pOriginalProcedure == 0)
		{
			CRectangle rectItem(Rectangle);
			if (m_pLayoutItem != nullptr)
			{
				rectItem.RemoveMargins(m_Margins);
				m_pLayoutItem->Lay(rectItem);
			}
		}
	}

	CSize CControlAdapter::GetMinimal()
	{
		CSize sizeControl = m_FixedSize;
		CSize sizeMinimal = CLayoutControl::GetMinimal();	
		
		if (m_FixedSize.Width() < sizeMinimal.Width())
			sizeControl.SetWidth(sizeMinimal.Width());
		
		if (m_FixedSize.Height() < sizeMinimal.Height())
			sizeControl.SetHeight(sizeMinimal.Height());

		return sizeControl;
	}

	void CControlAdapter::Hook()
	{
		m_mapProcedures.SetAt(m_pWnd->GetSafeHwnd(), this);
		m_pOriginalProcedure = reinterpret_cast<WNDPROC>(GetWindowLongPtr(m_pWnd->GetSafeHwnd(), GWLP_WNDPROC));

		// Set hook procedure
		if (::IsWindow(m_pWnd->GetSafeHwnd()) == TRUE)
			SetWindowLongPtr(m_pWnd->GetSafeHwnd(), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(HookProcedure));
	}

	LRESULT CALLBACK CControlAdapter::HookProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		LRESULT iResult = 0;

		CControlAdapter* pControlAdapter = 0;
		if (m_mapProcedures.Lookup(hWnd, pControlAdapter) == TRUE)
		{
			if (::IsWindow(hWnd) == TRUE)
				iResult = pControlAdapter->m_pOriginalProcedure(hWnd, message, wParam, lParam);

			if (message == WM_SIZE 
				/* message == WM_SHOWWINDOW */
				)
			{
				pControlAdapter->Lay();
			}			
		}

		return iResult;
	}

}