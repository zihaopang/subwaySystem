
// sbuwayColDlg.h : ͷ�ļ�
//
#include "m_showWin.h"
#pragma once
#include "afxwin.h"
// CsbuwayColDlg �Ի���
class CsbuwayColDlg : public CDialogEx
{
// ����
public:
	CsbuwayColDlg(CWnd* pParent = NULL);	// ��׼���캯��
	static UINT showCondition(void * param);
	bool flag;
	bool port_flag;
	bool setAllFlag = FALSE;
	bool set_flag = FALSE;
	CSpinButtonCtrl m_Spin;
	CComboBox m_portList;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SBUWAYCOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_showWin;
	afx_msg void OnBnClickedButton1();
	int com_port = 1;
	int m_doorNum = 1;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnCbnSelchangePortCombo();
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton4();
private:
	CStatic m_static;
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CFont m_doorInfo;
	CFont m_Font;
	CFont m_textWin;
	CFont m_doorFont;
	CFont m_door;
	CFont m_font1;
	CFont m_font2;
	CFont m_font3;
	CFont m_radBut1;
	CFont m_radBut2;
	CFont m_button1;
	CFont m_button2;
	CFont m_button3;
	CFont m_button4;
	CFont m_button5;
	CFont groupBox1;
	CFont groupBox2;
public:
	afx_msg void OnBnClickedButton5();
};
