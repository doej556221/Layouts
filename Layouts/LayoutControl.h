
// LayoutControl.h : Defines control item to use inside layout
//

#pragma once
#include "Layouts.h"
#include "LayoutItem.h"
#include "LayoutMargins.h"
#include "LayoutRect.h"

namespace Layouts
{
	class LAYOUTS_API CLayoutControl : public CLayoutItem
	{
	public:
		CLayoutControl();
		CLayoutControl(LayoutPolicy eHorizontalPolicy, LayoutPolicy eVerticalPolicy);
		virtual ~CLayoutControl();

		LayoutPolicy HorizontalPolicy();
		LayoutPolicy VerticalPolicy();
		void SetPolicy(LayoutPolicy eHorizontalPolicy, LayoutPolicy eVerticalPolicy);

		void Lay(const CRectangle& Rectangle) override;
		CSize GetMinimal() override;
		
		CLayoutItem* Layout() const;
		void SetLayout(CLayoutItem* pLayoutItem);
		
		CMargins GetMargins() const;
		void SetMargins(int iMargin);
		void SetMargins(int iLeft, int iTop, int iRight, int iBottom);
		void SetMargins(const CMargins& Margins);
		static void SetDefaultMargins(int iMargins);
		static void SetDefaultMargins(const CMargins& Margins);

	protected:

		static CMargins m_DefaultMargins;
		CMargins m_Margins;

		LayoutPolicy m_eHorizontalPolicy;
		LayoutPolicy m_eVerticalPolicy;

		CLayoutItem* m_pLayoutItem;
	};

}