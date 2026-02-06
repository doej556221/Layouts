
// LayoutSize.cpp : Defines size for control or layout
//

#include "pch.h"
#include "LayoutSize.h"
#include "LayoutMargins.h"

namespace Layouts
{

    CSize::CSize()
    {
        this->m_iWidth = 0;
        this->m_iHeight = 0;
    }

    CSize::CSize(const CSize& Size)
    {
        m_iWidth = Size.m_iWidth;
        m_iHeight = Size.m_iHeight;
    }

    CSize::CSize(int Width, int Height)
    {
        this->m_iWidth = Width;
        this->m_iHeight = Height;
    }

    int CSize::Width() const
    {
        return m_iWidth;
    }

    int CSize::Height() const
    {
        return m_iHeight;
    }

    void CSize::SetWidth(int iWidth)
    {
        m_iWidth = iWidth;
    }

    void CSize::SetHeight(int iHeight)
    {
        m_iHeight = iHeight;
    }

    void CSize::SetSize(const CSize& Size)
    {
        m_iWidth = Size.m_iWidth;
        m_iHeight = Size.m_iHeight;
    }

    void CSize::SetSize(int iWidth, int iHeight)
    {
        m_iWidth = iWidth;
        m_iHeight = iHeight;
    }

    void CSize::AddMargins(const CMargins& Margins)
    {
        m_iWidth = m_iWidth + Margins.Left() + Margins.Right();
        m_iHeight = m_iHeight + Margins.Top() + Margins.Bottom();
    }

    void CSize::RemoveMargins(const CMargins& Margins)
    {
        m_iWidth = m_iWidth - Margins.Left() - Margins.Right();
        m_iHeight = m_iHeight - Margins.Top() - Margins.Bottom();
    }
}