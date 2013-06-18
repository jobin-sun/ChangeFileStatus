// ChangeFileStatusDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ChangeFileStatus.h"
#include "ChangeFileStatusDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CChangeFileStatusDlg 对话框




CChangeFileStatusDlg::CChangeFileStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeFileStatusDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChangeFileStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChangeFileStatusDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CChangeFileStatusDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &CChangeFileStatusDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDOK, &CChangeFileStatusDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CChangeFileStatusDlg 消息处理程序

BOOL CChangeFileStatusDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChangeFileStatusDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChangeFileStatusDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChangeFileStatusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChangeFileStatusDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
CString pathName;
CString fileName;
void CChangeFileStatusDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fileDlg(TRUE);
	if( fileDlg.DoModal ()==IDOK )
	{

		pathName = fileDlg.GetPathName();
		fileName = fileDlg.GetFileTitle();
		CEditView* cd=(CEditView*)GetDlgItem(IDC_EDIT4);
		cd->SetWindowText(fileName);
		CDateTimeCtrl* cdt1=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2);
		CDateTimeCtrl* cdt2=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER3);
		CDateTimeCtrl* cdt3=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER4);
		CDateTimeCtrl* cdt4=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER5);
		//CFile file;
		//file.Open(pathName,CFile::modeRead);
		CFileStatus cfs;
		CFile::GetStatus(pathName,cfs);
		cdt1->SetTime(&cfs.m_ctime);
		cdt2->SetTime(&cfs.m_ctime);
		cdt3->SetTime(&cfs.m_mtime);
		cdt4->SetTime(&cfs.m_mtime);

		//SetWindowText(fileName);
	}
}

void CChangeFileStatusDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CChangeFileStatusDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDateTimeCtrl* cdt1=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2);
	CDateTimeCtrl* cdt2=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER3);
	CDateTimeCtrl* cdt3=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER4);
	CDateTimeCtrl* cdt4=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER5);
	//CFile file;
	//file.Open(pathName,CFile::modeRead);
	CFileStatus cfs;
	CFile::GetStatus(pathName,cfs);
	CTime t1,t2,t3,t4;
	cdt1->GetTime(t1);
	cdt2->GetTime(t2);
	cdt3->GetTime(t3);
	cdt4->GetTime(t4);
	cfs.m_ctime=CTime(t1.GetYear(),t1.GetMonth(),t1.GetDay(),t2.GetHour(),t2.GetMinute(),t2.GetSecond());
	cfs.m_mtime=CTime(t3.GetYear(),t3.GetMonth(),t3.GetDay(),t3.GetHour(),t4.GetMinute(),t4.GetSecond());
	CFile::SetStatus(pathName,cfs);
	OnOK();
}
