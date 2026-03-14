
/**
 * \file LayoutMargins.cpp
 * \~english @brief File for layout margins
 * \~english @details
 * This file contains implementation of classes and tools for layout margins
 * \~russian @brief Файл отступов содержимого размещений
 * \~russian @details
 * Этот файл содержит реализацию классов и средств для отступов размещений
 * \see LayoutPoint.cpp
 * \see LayoutSize.cpp
 * \see LayoutRect.cpp
 */

#include "pch.h"
#include "LayoutMargins.h"

namespace Layouts
{

	CLayoutMargins::CLayoutMargins()
	{
		m_iLeft = 0;
		m_iTop = 0;
		m_iRight = 0;
		m_iBottom = 0;
	}

	CLayoutMargins::CLayoutMargins(const CLayoutMargins& Margins)
	{
		m_iLeft = Margins.m_iLeft;
		m_iTop = Margins.m_iTop;
		m_iRight = Margins.m_iRight;
		m_iBottom = Margins.m_iBottom;
	}

	CLayoutMargins::CLayoutMargins(int iLeft, int iTop, int iRight, int iBottom)
	{
		m_iTop = iTop;
		m_iLeft = iLeft;
		m_iBottom = iBottom;
		m_iRight = iRight;
	}

	CLayoutMargins::CLayoutMargins(int iMargin)
	{
		m_iTop = iMargin;
		m_iLeft = iMargin;
		m_iBottom = iMargin;
		m_iRight = iMargin;
	}

	int CLayoutMargins::Left() const
	{
		return m_iLeft;
	}

	int CLayoutMargins::Top() const
	{
		return m_iTop;
	}

	int CLayoutMargins::Right() const
	{
		return m_iRight;
	}

	int CLayoutMargins::Bottom() const
	{
		return m_iBottom;
	}

	void CLayoutMargins::SetLeft(int iLeft)
	{
		m_iLeft = iLeft;
	}

	void CLayoutMargins::SetTop(int iTop)
	{
		m_iTop = iTop;
	}

	void CLayoutMargins::SetRight(int iRight)
	{
		m_iRight = iRight;
	}

	void CLayoutMargins::SetBottom(int iBottom)
	{
		m_iBottom = iBottom;
	}

	void CLayoutMargins::SetMargins(const CLayoutMargins& Margins)
	{
		m_iLeft = Margins.m_iLeft;
		m_iTop = Margins.m_iTop;
		m_iRight = Margins.m_iRight;
		m_iBottom = Margins.m_iBottom;
	}

	void CLayoutMargins::SetMargins(int iMargin)
	{
		m_iLeft = iMargin;
		m_iTop = iMargin;
		m_iRight = iMargin;
		m_iBottom = iMargin;
	}

	void CLayoutMargins::SetMargins(int iLeft, int iTop, int iRight, int iBottom)
	{
		m_iLeft = iLeft;
		m_iTop = iTop;
		m_iRight = iRight;
		m_iBottom = iBottom;
	}

}
