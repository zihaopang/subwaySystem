#pragma once


// CPortClose 对话框

class CPortClose : public CDialogEx
{
	DECLARE_DYNAMIC(CPortClose)

public:
	CPortClose(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPortClose();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
