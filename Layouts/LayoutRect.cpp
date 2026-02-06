
// LayoutRect.cpp : Defines rectagular area for control or layout
//

#include "pch.h"
#include "LayoutRect.h"
#include "LayoutPoint.h"
#include "LayoutSize.h"
#include "LayoutMargins.h"

namespace Layouts
{

	CRectangle::CRectangle()
	{
		m_iLeft = 0;
		m_iTop = 0;
		m_iRight = 0;
		m_iBottom = 0;
	}

	CRectangle::CRectangle(const CRectangle& Rectangle)
	{
		m_iLeft = Rectangle.m_iLeft;
		m_iTop = Rectangle.m_iTop;
		m_iRight = Rectangle.m_iRight;
		m_iBottom = Rectangle.m_iBottom;
	}

	CRectangle::CRectangle(int iLeft, int iTop, int iRight, int iBottom)
	{
		m_iLeft = iLeft;
		m_iTop = iTop;
		m_iRight = iRight;
		m_iBottom = iBottom;
	}

	CRectangle::CRectangle(const CPoint& Point, const CSize& Size)
	{
		m_iLeft = Point.Left();
		m_iTop = Point.Top();
		m_iRight = m_iLeft + Size.Width();
		m_iBottom = m_iTop + Size.Height();
	}

	int CRectangle::Left() const
	{
		return m_iLeft;
	}

	int CRectangle::Top() const
	{
		return m_iTop;
	}

	int CRectangle::Bottom() const
	{
		return m_iBottom;
	}

	int CRectangle::Right() const
	{
		return m_iRight;
	}

	int CRectangle::Width() const
	{
		return m_iRight - m_iLeft;
	}

	int CRectangle::Height() const
	{
		return m_iBottom - m_iTop;
	}

	void CRectangle::SetLeft(int iLeft)
	{
		m_iLeft = iLeft;
	}

	void CRectangle::SetTop(int iTop)
	{
		m_iTop = iTop;
	}

	void CRectangle::SetBottom(int iBottom)
	{
		m_iBottom = iBottom;
	}

	void CRectangle::SetRight(int iRight)
	{
		m_iRight = iRight;
	}

	CPoint CRectangle::Point() const
	{
		CPoint Point(m_iLeft, m_iTop);
		return Point;
	}

	void CRectangle::SetPoint(int iLeft, int iTop)
	{
		m_iLeft = iLeft;
		m_iTop = iTop;
	}

	void CRectangle::SetPoint(const CPoint& Point)
	{
		m_iLeft = Point.Left();
		m_iTop = Point.Top();
	}

	CSize CRectangle::Size() const
	{
		CSize Size(this->Width(), this->Height());
		return Size;
	}

	void CRectangle::SetSize(int iWidth, int iHeight)
	{
		m_iRight = m_iLeft + iWidth;
		m_iBottom = m_iTop + iHeight;
	}

	void CRectangle::SetSize(const CSize& Size)
	{
		m_iRight = m_iLeft + Size.Width();
		m_iBottom = m_iTop + Size.Height();
	}

	void CRectangle::SetWidth(int iWidth)
	{
		m_iRight = m_iLeft + iWidth;
	}

	void CRectangle::SetHeight(int iHeight)
	{
		m_iBottom = m_iTop + iHeight;
	}

	void CRectangle::SetRectangle(const CRectangle& Rectangle)
	{
		m_iLeft = Rectangle.m_iLeft;
		m_iTop = Rectangle.m_iTop;
		m_iRight = Rectangle.m_iRight;
		m_iBottom = Rectangle.m_iBottom;
	}

	void CRectangle::SetRectangle(const CPoint& Point, const CSize& Size)
	{
		m_iLeft = Point.Left();
		m_iTop = Point.Top();
		m_iRight = m_iLeft + Size.Height();
		m_iBottom = m_iTop + Size.Width();
	}

	void CRectangle::SetRectangle(int iLeft, int iTop, int iRight, int iBottom)
	{
		m_iLeft = iLeft;
		m_iTop = iTop;
		m_iRight = iRight;
		m_iBottom = iBottom;
	}

	void CRectangle::AddMargins(const CMargins& Margins)
	{
		m_iLeft = m_iLeft - Margins.Left();
		m_iTop = m_iTop - Margins.Top();
		m_iRight = m_iRight + Margins.Right();
		m_iBottom = m_iBottom + Margins.Bottom();
	}

	void CRectangle::AddMargins(int iMargins)
	{
		m_iLeft = m_iLeft - iMargins;
		m_iTop = m_iTop - iMargins;
		m_iRight = m_iRight + iMargins;
		m_iBottom = m_iBottom + iMargins;
	}

	void CRectangle::RemoveMargins(const CMargins& Margins)
	{
		m_iLeft = m_iLeft + Margins.Left();
		m_iTop = m_iTop + Margins.Top();
		m_iRight = m_iRight - Margins.Right();
		m_iBottom = m_iBottom - Margins.Bottom();
	}

	void CRectangle::RemoveMargins(int iMargins)
	{
		m_iLeft = m_iLeft + iMargins;
		m_iTop = m_iTop + iMargins;
		m_iRight = m_iRight - iMargins;
		m_iBottom = m_iBottom - iMargins;
	}
}