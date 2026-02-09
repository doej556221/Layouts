
// LayoutsGroup.h : Defines a group of controls or inner layouts
//

#pragma once
#include "Layouts.h"
#include "LayoutItem.h"

#include <list>

namespace Layouts
{
	class CSize;
	class CRectangle;
	class CMargins;
	class CLayoutControl;

	class LAYOUTS_API CLayoutGroup : public CLayoutItem
	{
	public:
		CLayoutGroup();
		CLayoutGroup(Orientation eOrientation);
		virtual ~CLayoutGroup();

	public:

		void AddItem(CLayoutControl* pControl);
		void RemoveItem(CLayoutControl* pControl);

		void AddItem(CLayoutItem* pItem);

		int CountItems();

		void Lay(const CRectangle& Rectangle) override;
		CSize GetMinimal() override;

		void SetOrientation(Orientation Value);

	protected:
		Orientation m_eOrientation;

		std::list<CLayoutControl*> m_arrItems;
	};

}