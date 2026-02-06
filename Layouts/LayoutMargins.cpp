
// LayoutMargins.cpp : Defines margins of control in layout
//

#include "pch.h"
#include "LayoutMargins.h"

namespace Layouts
{

	CMargins::CMargins()
	{
		m_iLeft = 0;
		m_iTop = 0;
		m_iRight = 0;
		m_iBottom = 0;
	}

	CMargins::CMargins(const CMargins& Margins)
	{
		m_iLeft = Margins.m_iLeft;
		m_iTop = Margins.m_iTop;
		m_iRight = Margins.m_iRight;
		m_iBottom = Margins.m_iBottom;
	}

	CMargins::CMargins(int iLeft, int iTop, int iRight, int iBottom)
	{
		m_iTop = iTop;
		m_iLeft = iLeft;
		m_iBottom = iBottom;
		m_iRight = iRight;
	}

	int CMargins::Left() const
	{
		return m_iLeft;
	}

	int CMargins::Top() const
	{
		return m_iTop;
	}

	int CMargins::Right() const
	{
		return m_iRight;
	}

	int CMargins::Bottom() const
	{
		return m_iBottom;
	}

	void CMargins::SetLeft(int iLeft)
	{
		m_iLeft = iLeft;
	}

	void CMargins::SetTop(int iTop)
	{
		m_iTop = iTop;
	}

	void CMargins::SetRight(int iRight)
	{
		m_iRight = iRight;
	}

	void CMargins::SetBottom(int iBottom)
	{
		m_iBottom = iBottom;
	}

	void CMargins::SetMargins(const CMargins& Margins)
	{
		m_iLeft = Margins.m_iLeft;
		m_iTop = Margins.m_iTop;
		m_iRight = Margins.m_iRight;
		m_iBottom = Margins.m_iBottom;
	}

	void CMargins::SetMargins(int iMargin)
	{
		m_iLeft = iMargin;
		m_iTop = iMargin;
		m_iRight = iMargin;
		m_iBottom = iMargin;
	}

	void CMargins::SetMargins(int iLeft, int iTop, int iRight, int iBottom)
	{
		m_iLeft = iLeft;
		m_iTop = iTop;
		m_iRight = iRight;
		m_iBottom = iBottom;
	}

}