
/**
 * \file LayoutItem.h
 * \brief Файл элемента размещений
 * \details
 * Этот файл содержит элемент размещений
 */

#ifndef LAYOUTITEM_HEADER
#define LAYOUTITEM_HEADER

#include "Layouts.h"

namespace Layouts
{
	class CSize;
	class CRectangle;
	class CMargins;

	/*!
	\class CLayoutItem
	\brief Класс элемента размещений
	\details
	Элемент размещений, который используется для расположения содержимого производными классами
	*/
	class LAYOUTS_API CLayoutItem
	{
	public:
		CLayoutItem();
		virtual ~CLayoutItem();

		virtual LayoutPolicy HorizontalPolicy();
		virtual LayoutPolicy VerticalPolicy();
		virtual bool IsVisible();

		virtual void Lay(const CRectangle& Rectangle);
		virtual CSize GetMinimal();

		int Spacing();
		static void SetDefaultSpacing(int iSpacing);
		void SetSpacing(int iSpacing);

	protected:

		static int m_iDefaultSpacing;
		int m_iSpacing;
	};

}

#endif
