
// LayoutsItem.h : Defines an abstract layout item inherit by controls or layouts
//

#pragma once
#include "Layouts.h"

namespace Layouts
{
	class CSize;
	class CRectangle;
	class CMargins;

	class LAYOUTS_API CLayoutItem
	{
	public:
		CLayoutItem();
		virtual ~CLayoutItem();

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