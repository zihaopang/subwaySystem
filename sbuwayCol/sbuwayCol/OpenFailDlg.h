#pragma once

#include "OPenFailDlg.h"
// COpenFailDlg 对话框

class COpenFailDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COpenFailDlg)

public:
	COpenFailDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COpenFailDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
