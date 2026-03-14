
/**
 * \file LayoutSize.cpp
 * \~english @brief File for layout size
 * \~english @details
 * This file contains implementation of classes and tools for layout size
 * \~russian @brief Файл для размера содержимого размещений
 * \~russian @details
 * Этот файл содержит реализацию классов и средств для размера размещений
 * \see LayoutPoint.cpp
 * \see LayoutRect.cpp
 */

#include "pch.h"
#include "LayoutSize.h"
#include "LayoutMargins.h"

namespace Layouts
{

    CLayoutSize::CLayoutSize()
    {
        this->m_iWidth = 0;
        this->m_iHeight = 0;
    }

    CLayoutSize::CLayoutSize(const CLayoutSize& Size)
    {
        m_iWidth = Size.m_iWidth;
        m_iHeight = Size.m_iHeight;
    }

    CLayoutSize::CLayoutSize(int Width, int Height)
    {
        this->m_iWidth = Width;
        this->m_iHeight = Height;
    }

    int CLayoutSize::Width() const
    {
        return m_iWidth;
    }

    int CLayoutSize::Height() const
    {
        return m_iHeight;
    }

    void CLayoutSize::SetWidth(int iWidth)
    {
        m_iWidth = iWidth;
    }

    void CLayoutSize::SetHeight(int iHeight)
    {
        m_iHeight = iHeight;
    }

    void CLayoutSize::SetSize(const CLayoutSize& Size)
    {
        m_iWidth = Size.m_iWidth;
        m_iHeight = Size.m_iHeight;
    }

    void CLayoutSize::SetSize(int iWidth, int iHeight)
    {
        m_iWidth = iWidth;
        m_iHeight = iHeight;
    }

    void CLayoutSize::AddMargins(const CLayoutMargins& Margins)
    {
        m_iWidth = m_iWidth + Margins.Left() + Margins.Right();
        m_iHeight = m_iHeight + Margins.Top() + Margins.Bottom();
    }

    void CLayoutSize::AddMargins(int iMargin)
    {
        m_iWidth = m_iWidth + iMargin + iMargin;
        m_iHeight = m_iHeight + iMargin + iMargin;
    }

    void CLayoutSize::RemoveMargins(const CLayoutMargins& Margins)
    {
        m_iWidth = m_iWidth - Margins.Left() - Margins.Right();
        m_iHeight = m_iHeight - Margins.Top() - Margins.Bottom();
    }

    void CLayoutSize::RemoveMargins(int iMargin)
    {
        m_iWidth = m_iWidth - iMargin - iMargin;
        m_iHeight = m_iHeight - iMargin - iMargin;
    }

}

