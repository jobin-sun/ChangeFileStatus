// ChangeFileStatusDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChangeFileStatus.h"
#include "ChangeFileStatusDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CChangeFileStatusDlg �Ի���




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


// CChangeFileStatusDlg ��Ϣ�������

BOOL CChangeFileStatusDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChangeFileStatusDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CChangeFileStatusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChangeFileStatusDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
CString pathName;
CString fileName;
void CChangeFileStatusDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CChangeFileStatusDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
