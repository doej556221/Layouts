
// LabelAdapter.h: Defines MFC Label Control based on LayoutControl class
//

#pragma once
#include "ControlAdapter.h"
#include "LayoutSize.h"

namespace Layouts
{
	class CLayoutRectangle;
	class CLayoutMargins;

	class CLabelAdapter : public CControlAdapter
	{
	public:
		CLabelAdapter(CWnd* pWnd);
		CLabelAdapter(CWnd* pWnd, LayoutPolicy eHorizontal, LayoutPolicy eVertical);
		virtual ~CLabelAdapter();

		CLayoutSize GetMinimal() override;

	protected:
		Layouts::CLayoutSize m_MinimalSize;
	};

}
