#pragma once


// CPortErrDlg 对话框

class CPortErrDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPortErrDlg)

public:
	CPortErrDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPortErrDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
