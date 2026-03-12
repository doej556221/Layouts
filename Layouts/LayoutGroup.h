
/**
 * \file LayoutGroup.h
 * \brief Файл группы контролов и размещений
 * \details
 * Этот файл содержит группы контролов и размещений
 * \see LayoutItem.h
 */

#ifndef LAYOUTGROUP_HEADER
#define LAYOUTGROUP_HEADER

#include "Layouts.h"
#include "LayoutItem.h"

#include <list>

namespace Layouts
{
	class CSize;
	class CRectangle;
	class CMargins;
	class CLayoutControl;

	/*!
	\class CLayoutGroup
	\brief Элемент размещения в группе
	\details
	Элемент размешения контролов и вложенных размещений в группе по горизонтали или вертикали
	*/
	class LAYOUTS_API CLayoutGroup : public CLayoutItem
	{
	public:
		CLayoutGroup();
		CLayoutGroup(Orientation eOrientation);
		virtual ~CLayoutGroup();

	public:

		void AddItem(CLayoutItem* pControl);
		void RemoveItem(CLayoutItem* pControl);

		int CountItems();

		LayoutPolicy HorizontalPolicy() override;
		LayoutPolicy VerticalPolicy() override;
		bool IsVisible() override;

		void Lay(const CRectangle& Rectangle) override;
		CSize GetMinimal() override;

		void SetOrientation(Orientation Value);

	protected:
		Orientation m_eOrientation;

		std::list<CLayoutItem*> m_arrItems;
	};

}

#endif
