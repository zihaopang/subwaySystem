#pragma once

#include "OPenFailDlg.h"
// COpenFailDlg �Ի���

class COpenFailDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COpenFailDlg)

public:
	COpenFailDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COpenFailDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
