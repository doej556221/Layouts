
// LayoutsDlg.cpp : dialog implementation file
//

#include "pch.h"
#include "framework.h"
#include "LayoutsApp.h"
#include "LayoutsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "LayoutControl.h"
#include "LayoutGroup.h"
#include "Control.h"

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CLayoutsDlg dialog

CLayoutsDlg::CLayoutsDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LAYOUTSAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLayoutsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLayoutsDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CLayoutsDlg message handlers

BOOL CLayoutsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Add extra initialization here
	
	Layouts::CMFCControl* itemForm = new Layouts::CMFCControl(this, Layouts::Preferred, Layouts::Preferred);
	itemForm->SetMargins(5);
	
	Layouts::CLayoutGroup* groupForm = new Layouts::CLayoutGroup(Layouts::Vertical);
	itemForm->SetLayout(groupForm);

	// Name Fields

	Layouts::CLayoutGroup* groupFirstName = new Layouts::CLayoutGroup(Layouts::Horizontal);
	Layouts::CMFCControl* itemFirstNameLabel = new Layouts::CMFCControl(GetDlgItem(IDC_STATIC1), Layouts::Fixed, Layouts::Fixed);
	Layouts::CMFCControl* itemFirstNameEdit = new Layouts::CMFCControl(GetDlgItem(IDC_EDIT1), Layouts::Stretched, Layouts::Fixed);
	groupFirstName->AddItem(itemFirstNameLabel);
	groupFirstName->AddItem(itemFirstNameEdit);
	groupForm->AddItem(groupFirstName);

	Layouts::CLayoutGroup* groupLastName = new Layouts::CLayoutGroup(Layouts::Horizontal);
	Layouts::CMFCControl* itemLastNameLabel = new Layouts::CMFCControl(GetDlgItem(IDC_STATIC2), Layouts::Fixed, Layouts::Fixed);
	Layouts::CMFCControl* itemLastNameEdit = new Layouts::CMFCControl(GetDlgItem(IDC_EDIT2), Layouts::Stretched, Layouts::Fixed);
	groupLastName->AddItem(itemLastNameLabel);
	groupLastName->AddItem(itemLastNameEdit);
	groupForm->AddItem(groupLastName);

	// Contact Fields

	Layouts::CMFCControl* itemContacts = new Layouts::CMFCControl(GetDlgItem(IDC_STATIC3), Layouts::Preferred, Layouts::Preferred);
	itemContacts->SetMargins(10, 20, 10, 10);
	groupForm->AddItem(itemContacts);

	Layouts::CLayoutGroup* groupContacts = new Layouts::CLayoutGroup(Layouts::Vertical);
	itemContacts->SetLayout(groupContacts);

	Layouts::CLayoutGroup* groupPhone = new Layouts::CLayoutGroup(Layouts::Horizontal);
	Layouts::CMFCControl* itemPhoneLabel = new Layouts::CMFCControl(GetDlgItem(IDC_STATIC4), Layouts::Fixed, Layouts::Fixed);
	Layouts::CMFCControl* itemPhoneEdit = new Layouts::CMFCControl(GetDlgItem(IDC_EDIT4), Layouts::Stretched, Layouts::Fixed);
	groupPhone->AddItem(itemPhoneLabel);
	groupPhone->AddItem(itemPhoneEdit);
	groupContacts->AddItem(groupPhone);

	Layouts::CLayoutGroup* groupEmail = new Layouts::CLayoutGroup(Layouts::Horizontal);
	Layouts::CMFCControl* itemEmailLabel = new Layouts::CMFCControl(GetDlgItem(IDC_STATIC5), Layouts::Fixed, Layouts::Fixed);
	Layouts::CMFCControl* itemEmailEdit = new Layouts::CMFCControl(GetDlgItem(IDC_EDIT5), Layouts::Stretched, Layouts::Fixed);
	groupEmail->AddItem(itemEmailLabel);
	groupEmail->AddItem(itemEmailEdit);
	groupContacts->AddItem(groupEmail);

	// Control Buttons

	Layouts::CLayoutGroup* groupControls = new Layouts::CLayoutGroup(Layouts::Horizontal);

	Layouts::CMFCControl* itemSave = new Layouts::CMFCControl(GetDlgItem(IDC_BUTTON1), Layouts::Fixed, Layouts::Fixed);
	Layouts::CMFCControl* itemReset = new Layouts::CMFCControl(GetDlgItem(IDC_BUTTON2), Layouts::Fixed, Layouts::Fixed);
	Layouts::CMFCControl* itemPrint = new Layouts::CMFCControl(GetDlgItem(IDC_BUTTON3), Layouts::Fixed, Layouts::Fixed);
	Layouts::CMFCControl* itemSubmit = new Layouts::CMFCControl(GetDlgItem(IDC_BUTTON4), Layouts::Fixed, Layouts::Fixed);

	groupControls->AddItem(itemSave);
	groupControls->AddItem(itemReset);
	groupControls->AddItem(itemPrint);
	groupControls->AddItem(itemSubmit);

	groupForm->AddItem(groupControls);

	// Dialog Buttons

	Layouts::CLayoutGroup* groupDialog = new Layouts::CLayoutGroup(Layouts::Horizontal);

	Layouts::CMFCControl* itemOk = new Layouts::CMFCControl(GetDlgItem(IDOK), Layouts::Preferred, Layouts::Fixed);
	Layouts::CMFCControl* itemCancel = new Layouts::CMFCControl(GetDlgItem(IDCANCEL), Layouts::Preferred, Layouts::Fixed);

	groupDialog->AddItem(itemOk);
	groupDialog->AddItem(itemCancel);

	groupForm->AddItem(groupDialog);

	// Layout

	itemForm->Lay();
	itemForm->Hook();
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLayoutsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLayoutsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLayoutsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

