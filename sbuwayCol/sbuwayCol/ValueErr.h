#pragma once


// CValueErr �Ի���

class CValueErr : public CDialogEx
{
	DECLARE_DYNAMIC(CValueErr)

public:
	CValueErr(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CValueErr();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
