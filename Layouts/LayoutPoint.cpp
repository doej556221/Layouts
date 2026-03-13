
/**
 * \file LayoutPoint.cpp
 * \~english @brief File for layout point
 * \~english @details
 * This file contains implementation of classes and tools for layout point
 * \~russian @brief Файл точки для содержимого размещений
 * \~russian @details
 * Этот файл содержит реализацию классов и средств для точки размещений
 * \see LayoutSize.cpp
 * \see LayoutRect.cpp
 * \see LayoutMargins.cpp
 */

#include "pch.h"
#include "LayoutPoint.h"

namespace Layouts
{
	CPoint::CPoint()
	{
		m_iTop = 0;
		m_iLeft = 0;
	}

	CPoint::CPoint(const CPoint& Point)
	{
		m_iLeft = Point.m_iLeft;
		m_iTop = Point.m_iTop;
	}

	CPoint::CPoint(int iLeft, int iTop)
	{
		m_iLeft = iLeft;
		m_iTop = iTop;
	}

	int CPoint::Top() const
	{
		return m_iTop;
	}

	int CPoint::Left() const
	{
		return m_iLeft;
	}

	void CPoint::SetLeft(int iLeft)
	{
		m_iLeft = iLeft;
	}

	void CPoint::SetTop(int iTop)
	{
		m_iTop = iTop;
	}

	void CPoint::SetPoint(const CPoint& Point)
	{
		m_iTop = Point.m_iTop;
		m_iLeft = Point.m_iLeft;
	}

	void CPoint::SetPoint(int iLeft, int iTop)
	{
		m_iLeft = iLeft;
		m_iTop = iTop;
	}

}
