
// Control.h: Defines MFC Control based on LayoutControl class
//

#include "LayoutControl.h"
#include "LayoutSize.h"

namespace Layouts
{
	class CRectangle;
	class CMargins;

	class CMFCControl : public CLayoutControl
	{
	public:
		CMFCControl(CWnd* pWnd);
		CMFCControl(CWnd* pWnd, LayoutPolicy eHorizontal, LayoutPolicy eVertical);
		virtual ~CMFCControl();

		void Lay();
		void Lay(const CRectangle& Rectangle) override;
		CSize GetMinimal() override;

		void Hook();

	protected:
		CWnd* m_pWnd;
		Layouts::CSize m_FixedSize;

		WNDPROC m_pOriginalProcedure;
		static LRESULT CALLBACK HookProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		static CMap<HWND, HWND, CMFCControl*, CMFCControl*> m_mapProcedures;
	};

}