// ChangeFileStatus.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CChangeFileStatusApp:
// �йش����ʵ�֣������ ChangeFileStatus.cpp
//

class CChangeFileStatusApp : public CWinApp
{
public:
	CChangeFileStatusApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CChangeFileStatusApp theApp;