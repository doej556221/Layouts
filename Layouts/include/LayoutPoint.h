
/**
 * \file LayoutPoint.h
 * \brief Файл средств работы с положением содержимого размещений
 * \details
 * Этот файл содержит средства работы с положением содержимого размещений
 * \see LayoutSize.h
 * \see LayoutRect.h
 * \see LayoutMargins.h
 */

#ifndef LAYOUTPOINT_HADER
#define LAYOUTPOINT_HADER

#include "Layouts.h"

namespace Layouts
{
	/*!
	\class CPoint
	\brief Точка размещения
	\details
	Точка, которая используется для расположения содержимого размещений
	*/
	class LAYOUTS_API CPoint
	{
		int m_iTop; ///< Положение точки по вертикали
		int m_iLeft; ///< Положение точки по горизонтали

	public:
		CPoint();
		CPoint(const CPoint& Point);
		CPoint(int iLeft, int iTop);

		int Top() const;
		int Left() const;

		void SetLeft(int iLeft);
		void SetTop(int iTop);
		
		void SetPoint(const CPoint& Point);
		void SetPoint(int iLeft, int iTop);
	};

}

#endif