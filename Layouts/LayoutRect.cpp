
/**
 * \file LayoutRect.cpp
 * \~english @brief File for layout rectangle
 * \~english @details
 * This file contains implementation of classes and tools for layout rectangle
 * \~russian @brief Файл прямоугольника содержимого размещений
 * \~russian @details
 * Этот файл содержит реализацию классов и средств для прямоугольника
 * \see LayoutPoint.cpp
 * \see LayoutSize.cpp
 * \see LayoutMargins.cpp
 */

#include "pch.h"
#include "LayoutRect.h"
#include "LayoutPoint.h"
#include "LayoutSize.h"
#include "LayoutMargins.h"

namespace Layouts
{

	CLayoutRectangle::CLayoutRectangle()
	{
		m_iLeft = 0;
		m_iTop = 0;
		m_iRight = 0;
		m_iBottom = 0;
	}

	CLayoutRectangle::CLayoutRectangle(const CLayoutRectangle& Rectangle)
	{
		m_iLeft = Rectangle.m_iLeft;
		m_iTop = Rectangle.m_iTop;
		m_iRight = Rectangle.m_iRight;
		m_iBottom = Rectangle.m_iBottom;
	}

	CLayoutRectangle::CLayoutRectangle(int iLeft, int iTop, int iRight, int iBottom)
	{
		m_iLeft = iLeft;
		m_iTop = iTop;
		m_iRight = iRight;
		m_iBottom = iBottom;
	}

	CLayoutRectangle::CLayoutRectangle(const CLayoutPoint& Point, const CLayoutSize& Size)
	{
		m_iLeft = Point.Left();
		m_iTop = Point.Top();
		m_iRight = m_iLeft + Size.Width();
		m_iBottom = m_iTop + Size.Height();
	}

	int CLayoutRectangle::Left() const
	{
		return m_iLeft;
	}

	int CLayoutRectangle::Top() const
	{
		return m_iTop;
	}

	int CLayoutRectangle::Bottom() const
	{
		return m_iBottom;
	}

	int CLayoutRectangle::Right() const
	{
		return m_iRight;
	}

	int CLayoutRectangle::Width() const
	{
		return m_iRight - m_iLeft;
	}

	int CLayoutRectangle::Height() const
	{
		return m_iBottom - m_iTop;
	}

	void CLayoutRectangle::SetLeft(int iLeft)
	{
		m_iLeft = iLeft;
	}

	void CLayoutRectangle::SetTop(int iTop)
	{
		m_iTop = iTop;
	}

	void CLayoutRectangle::SetBottom(int iBottom)
	{
		m_iBottom = iBottom;
	}

	void CLayoutRectangle::SetRight(int iRight)
	{
		m_iRight = iRight;
	}

	CLayoutPoint CLayoutRectangle::Point() const
	{
		CLayoutPoint Point(m_iLeft, m_iTop);
		return Point;
	}

	void CLayoutRectangle::SetPoint(int iLeft, int iTop)
	{
		m_iLeft = iLeft;
		m_iTop = iTop;
	}

	void CLayoutRectangle::SetPoint(const CLayoutPoint& Point)
	{
		m_iLeft = Point.Left();
		m_iTop = Point.Top();
	}

	CLayoutSize CLayoutRectangle::Size() const
	{
		CLayoutSize Size(this->Width(), this->Height());
		return Size;
	}

	void CLayoutRectangle::SetSize(int iWidth, int iHeight)
	{
		m_iRight = m_iLeft + iWidth;
		m_iBottom = m_iTop + iHeight;
	}

	void CLayoutRectangle::SetSize(const CLayoutSize& Size)
	{
		m_iRight = m_iLeft + Size.Width();
		m_iBottom = m_iTop + Size.Height();
	}

	void CLayoutRectangle::SetWidth(int iWidth)
	{
		m_iRight = m_iLeft + iWidth;
	}

	void CLayoutRectangle::SetHeight(int iHeight)
	{
		m_iBottom = m_iTop + iHeight;
	}

	void CLayoutRectangle::SetRectangle(const CLayoutRectangle& Rectangle)
	{
		m_iLeft = Rectangle.m_iLeft;
		m_iTop = Rectangle.m_iTop;
		m_iRight = Rectangle.m_iRight;
		m_iBottom = Rectangle.m_iBottom;
	}

	void CLayoutRectangle::SetRectangle(const CLayoutPoint& Point, const CLayoutSize& Size)
	{
		m_iLeft = Point.Left();
		m_iTop = Point.Top();
		m_iRight = m_iLeft + Size.Height();
		m_iBottom = m_iTop + Size.Width();
	}

	void CLayoutRectangle::SetRectangle(int iLeft, int iTop, int iRight, int iBottom)
	{
		m_iLeft = iLeft;
		m_iTop = iTop;
		m_iRight = iRight;
		m_iBottom = iBottom;
	}

	void CLayoutRectangle::AddMargins(const CLayoutMargins& Margins)
	{
		m_iLeft = m_iLeft - Margins.Left();
		m_iTop = m_iTop - Margins.Top();
		m_iRight = m_iRight + Margins.Right();
		m_iBottom = m_iBottom + Margins.Bottom();
	}

	void CLayoutRectangle::AddMargins(int iMargins)
	{
		m_iLeft = m_iLeft - iMargins;
		m_iTop = m_iTop - iMargins;
		m_iRight = m_iRight + iMargins;
		m_iBottom = m_iBottom + iMargins;
	}

	void CLayoutRectangle::RemoveMargins(const CLayoutMargins& Margins)
	{
		m_iLeft = m_iLeft + Margins.Left();
		m_iTop = m_iTop + Margins.Top();
		m_iRight = m_iRight - Margins.Right();
		m_iBottom = m_iBottom - Margins.Bottom();
	}

	void CLayoutRectangle::RemoveMargins(int iMargins)
	{
		m_iLeft = m_iLeft + iMargins;
		m_iTop = m_iTop + iMargins;
		m_iRight = m_iRight - iMargins;
		m_iBottom = m_iBottom - iMargins;
	}
}
