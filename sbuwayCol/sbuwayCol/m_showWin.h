#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// m_showWin 对话框

class m_showWin : public CDialogEx
{
	DECLARE_DYNAMIC(m_showWin)

public:
	m_showWin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~m_showWin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SBUWAYCOL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedInfo();
};
