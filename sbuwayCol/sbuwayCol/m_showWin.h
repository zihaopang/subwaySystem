#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// m_showWin �Ի���

class m_showWin : public CDialogEx
{
	DECLARE_DYNAMIC(m_showWin)

public:
	m_showWin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~m_showWin();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SBUWAYCOL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedInfo();
};
