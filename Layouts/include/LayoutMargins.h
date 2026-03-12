
/**
 * \file LayoutMargins.h
 * \brief Файл средств работы с отступами содержимого размещений
 * \details
 * Этот файл содержит средства работы с отступами содержимого размещений
 * \see LayoutPoint.h
 * \see LayoutSize.h
 * \see LayoutRect.h
 */

#ifndef LAYOUTMARGINS_HEADER
#define LAYOUTMARGINS_HEADER

#include "Layouts.h"

namespace Layouts
{
	/*!
	\class CMargins
	\brief Отступ
	\details
	Отступ, который используется для расположения содержимого размещений
	*/
	class LAYOUTS_API CMargins
	{
		int m_iTop; ///< Отступ сверху
		int m_iLeft; ///< Отступ слева
		int m_iBottom; ///< Отступ снизу
		int m_iRight; ///< Отступ справа

	public:
		CMargins();
		CMargins(const CMargins& Margins);
		CMargins(int iTop, int iLeft, int iBottom, int iRight);

		int Top() const;
		int Left() const;
		int Bottom() const;
		int Right() const;

		void SetLeft(int iLeft);
		void SetTop(int iTop);
		void SetRight(int iRight);
		void SetBottom(int iBottom);

		void SetMargins(const CMargins& Margins);
		void SetMargins(int iMargin);
		void SetMargins(int iLeft, int iTop, int iRight, int iBottom);
	};

}

#endif
