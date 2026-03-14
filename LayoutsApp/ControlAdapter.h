
// Control.h: Defines MFC Control based on LayoutControl class
//

#include "LayoutControl.h"
#include "LayoutSize.h"

namespace Layouts
{
	class CLayoutRectangle;
	class CLayoutMargins;

	class CControlAdapter : public CLayoutControl
	{
	public:
		CControlAdapter(CWnd* pWnd);
		CControlAdapter(CWnd* pWnd, LayoutPolicy eHorizontal, LayoutPolicy eVertical);
		virtual ~CControlAdapter();

		bool IsVisible() override;

		void Lay();
		void Lay(const CLayoutRectangle& Rectangle) override;
		CLayoutSize GetMinimal() override;

		void Hook();

	protected:
		CWnd* m_pWnd;
		Layouts::CLayoutSize m_FixedSize;

		WNDPROC m_pOriginalProcedure;
		static LRESULT CALLBACK HookProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		static CMap<HWND, HWND, CControlAdapter*, CControlAdapter*> m_mapProcedures;
	};

}
