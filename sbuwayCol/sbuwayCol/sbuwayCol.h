
// sbuwayCol.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#include "com.h"

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CsbuwayColApp: 
// �йش����ʵ�֣������ sbuwayCol.cpp
//

class CsbuwayColApp : public CWinApp
{
public:
	CsbuwayColApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CsbuwayColApp theApp;