#pragma once


// CPortClose �Ի���

class CPortClose : public CDialogEx
{
	DECLARE_DYNAMIC(CPortClose)

public:
	CPortClose(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPortClose();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
