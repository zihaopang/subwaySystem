#pragma once


// CPortErrDlg �Ի���

class CPortErrDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPortErrDlg)

public:
	CPortErrDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPortErrDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
