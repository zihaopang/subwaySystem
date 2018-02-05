// sbuwayColDlg.cpp : ʵ���ļ�

#include "stdafx.h"
#include "sbuwayCol.h"
#include "sbuwayColDlg.h"
#include "afxdialogex.h"
#include "OpenFailDlg.h"
#include "PortErrDlg.h"
#include "ValueErr.h"
#include "PortClose.h"
#include "afxwin.h"
#include "afxcmn.h"

#define BUF_LEN 100

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CsbuwayColDlg �Ի���



CsbuwayColDlg::CsbuwayColDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SBUWAYCOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsbuwayColDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_showWin);
	DDX_Control(pDX, IDC_PORT_COMBO, m_portList);
	DDX_Text(pDX, IDC_EDIT2, m_doorNum);
	DDX_Control(pDX, IDC_TITLE, m_static);
	DDX_Control(pDX, IDC_TITLE, m_static);
	//DDX_Control(pDX, DOOR_INFO, m_doorInfo);

	DDX_Control(pDX,PORT_NUM, m_static1);
	DDX_Control(pDX, DOOR_NM, m_static2);
	DDX_Control(pDX, DOOR_STA, m_static3);
}

BEGIN_MESSAGE_MAP(CsbuwayColDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CsbuwayColDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CsbuwayColDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CsbuwayColDlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_PORT_COMBO, &CsbuwayColDlg::OnCbnSelchangePortCombo)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CsbuwayColDlg::OnDeltaposSpin1)
	ON_BN_CLICKED(IDC_BUTTON4, &CsbuwayColDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CsbuwayColDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CsbuwayColDlg ��Ϣ�������

BOOL CsbuwayColDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//���ñ�������  
	m_Font.CreatePointFont(300, _T("�����п�"), NULL);
	m_static.SetFont(&m_Font, true);
	m_static.SetWindowText(_T("�� �� �� ״ ̬ �� Ϣ �� �� ϵ ͳ"));

	//���ñ༭������
	CEdit *m_EditAa = (CEdit *)GetDlgItem(IDC_EDIT1);
	m_textWin.CreatePointFont(180, _T("����"));
	m_EditAa->SetFont(&m_textWin);
	//�����źű༭������
	CEdit *m_EditBa = (CEdit *)GetDlgItem(IDC_EDIT2);
	m_door.CreatePointFont(150, _T("����"));
	m_EditBa->SetFont(&m_door);
	//����RADIO BUTTON����
	CEdit *m_EditCa = (CEdit *)GetDlgItem(IDC_RADIO1);
	m_radBut1.CreatePointFont(150, _T("����"));
	m_EditCa->SetFont(&m_radBut1);
	CEdit *m_EditDa = (CEdit *)GetDlgItem(IDC_RADIO2);
	m_radBut2.CreatePointFont(150, _T("����"));
	m_EditDa->SetFont(&m_radBut2);
	//���ð�ť����
	CEdit *m_EditEa = (CEdit *)GetDlgItem(IDC_BUTTON1);
	m_button1.CreatePointFont(150, _T("����"));
	m_EditEa->SetFont(&m_button1);
	CEdit *m_EditFa = (CEdit *)GetDlgItem(IDC_BUTTON2);
	m_button2.CreatePointFont(150, _T("����"));
	m_EditFa->SetFont(&m_button2);
	CEdit *m_EditGa = (CEdit *)GetDlgItem(IDC_BUTTON3);
	m_button3.CreatePointFont(150, _T("����"));
	m_EditGa->SetFont(&m_button3);
	CEdit *m_EditHa = (CEdit *)GetDlgItem(IDC_BUTTON4);
	m_button4.CreatePointFont(150, _T("����"));
	m_EditHa->SetFont(&m_button4);
	CEdit *m_EditLa = (CEdit *)GetDlgItem(IDC_BUTTON5);
	m_button5.CreatePointFont(150, _T("����"));
	m_EditLa->SetFont(&m_button5);
	//����group box����
	CEdit *m_EditIa = (CEdit *)GetDlgItem(IDC_GRP1);
	groupBox1.CreatePointFont(200, _T("����"));
	m_EditIa->SetFont(&groupBox1);
	CEdit *m_EditJa = (CEdit *)GetDlgItem(IDC_GRP2);
	groupBox2.CreatePointFont(200, _T("����"));
	m_EditJa->SetFont(&groupBox2);

	//������������
	m_font1.CreatePointFont(200, _T("����"), NULL);
	m_static1.SetFont(&m_doorFont, true);
	m_static1.SetWindowText(_T("���ں�:"));

	m_font2.CreatePointFont(200, _T("����"), NULL);
	m_static2.SetFont(&m_doorFont, true);
	m_static2.SetWindowText(_T("�ź�:"));

	m_font3.CreatePointFont(200, _T("����"), NULL);
	m_static3.SetFont(&m_doorFont, true);
	m_static3.SetWindowText(_T("��״̬:"));

	//������״̬����
	CEdit *m_EditKa = (CEdit *)GetDlgItem(DOOR_INFO);
	m_doorInfo.CreatePointFont(200, _T("����"));
	m_EditKa->SetFont(&m_doorInfo);

	CheckRadioButton(IDC_RADIO1, //��һ������Ϊ����ĵ�һ����ѡ��ť��ID   

		IDC_RADIO2, //�ڶ�������Ϊ��������һ����ѡ��ť��ID   

		IDC_RADIO2); //����������Ϊ�����б�ѡ�еĵ�ѡ��ť��ID     

	CEdit*  pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit->SetWindowText(_T("1"));

	port_flag = FALSE;

	m_portList.AddString(_T("COM1"));
	m_portList.AddString(_T("COM2"));
	m_portList.AddString(_T("COM3"));
	m_portList.AddString(_T("COM4"));
	// Ĭ��ѡ���һ��
	m_portList.SetCurSel(0);
	SetDlgItemText(IDC_PORT_COMBO, _T("COM1"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CsbuwayColDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CsbuwayColDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CsbuwayColDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CsbuwayColDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;
	int iResult;
	COpenFailDlg OpenFail;
	CPortErrDlg PortErr;

	UpdateData(TRUE); // �����ؼ��е����ݱ��浽��Ӧ�ı���
	
	iResult = OpenComPort(com_port, 9600);

	if (FALSE == iResult)
	{
		nRes = OpenFail.DoModal();

		if (IDCANCEL == nRes)
		{
			UpdateData(FALSE);
			return;
		}
	}
	else
	{	
		m_showWin.SetWindowText(_T("���ڴ򿪳ɹ�"));
		port_flag = TRUE;
	}
}

void CsbuwayColDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CloseComPort();
	flag = FALSE;
	m_showWin.SetWindowText(_T("�����ѹر�"));
}

UINT CsbuwayColDlg::showCondition(void * param)
{
	int i;
	int j;
	MSG   msg;
	int numRecord = 0;
	TCHAR showBuf[20] = {0};
	unsigned char temp[2] = {0};
	unsigned char rcvBuf[BUF_LEN] = {0};
	unsigned char doorSta[10] = { 0 };
	memset(rcvBuf, 0, BUF_LEN);

	CsbuwayColDlg *dlg = (CsbuwayColDlg*)param;
	CEdit *SysTimeBox = (CEdit*)dlg->GetDlgItem(IDC_EDIT1);

	while (dlg->flag)
	{
		for (i = 0; i < BUF_LEN; i++)
		{
			ReceiveMessage(temp, 2, 2);
			rcvBuf[i] = temp[0];
			temp[0] = 0;
			temp[1] = 0;
		}

		for (j = 1; j < 11; j++)
		{
			for (i = 0; i < BUF_LEN; i++)
			{
				if ((rcvBuf[i] >> 4) == j)
				{
					doorSta[j - 1] = rcvBuf[i];
					numRecord++;
					break;
				}
			}
		}

		//��������
		SysTimeBox->SetSel(-1);
		//��ӡ����Ϣ
		if (numRecord == 0)
		{
			SysTimeBox->SetWindowText(_T(""));
			SysTimeBox->SetWindowText(_T("������\n"));
		}
		else
		{
			SysTimeBox->UpdateData(true);
			for (i = 0; i < 10; i++)
			{
				if (doorSta[i] != 0 && doorSta[i] != 0xaa && doorSta[i] != 0x55)
				{
					wsprintf(showBuf, _T("\r\n%d����"), doorSta[i] >> 4);

					if ((doorSta[i] & 0x0f) == 0x03)
					{
						wsprintf(showBuf, _T("%s:��\r\n"), showBuf);
					}
					else if ((doorSta[i] & 0x0f) == 0x0c)
					{
						wsprintf(showBuf, _T("%s:�ر�\r\n"), showBuf);
					}
					else
					{
						wsprintf(showBuf, _T("%s:״̬δ֪\r\n"), showBuf);
					}
					SysTimeBox->ReplaceSel(showBuf);  
					//SysTimeBox->Invalidate(FALSE);
				}
			}
			numRecord = 0;
		}
		memset(showBuf, 0, 20);
		memset(doorSta, 0, 10);
		memset(rcvBuf, 0, 100);
		if (FALSE == dlg->set_flag)
		{
			resetComPort();
		}
		Sleep(3000);
		SysTimeBox->SetWindowText(_T(""));
		SysTimeBox->UpdateData(false);
	}
}

void CsbuwayColDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (flag)
	{
		flag = FALSE;
		GetDlgItem(IDC_BUTTON3)->SetWindowTextW(_T("��ʼ�ϱ�"));
	}
	else
	{
		AfxBeginThread(showCondition, this, THREAD_PRIORITY_IDLE);

		flag = true;
		GetDlgItem(IDC_BUTTON3)->SetWindowTextW(_T("ֹͣ�ϱ�"));
	}
}

void CsbuwayColDlg::OnCbnSelchangePortCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nSel;
	// ��ȡ��Ͽ�ؼ����б����ѡ���������
	nSel = m_portList.GetCurSel();
	// ����ѡ����������ȡ�����ַ���
	com_port = nSel + 1;
}


void CsbuwayColDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;
	CValueErr ValueErrDlg;

	UpdateData(true);
	if (pNMUpDown->iDelta == -1) // �����ֵΪ-1 , ˵�������Spin�����µļ�ͷ  
	{
		m_doorNum++;
	}
	else if (pNMUpDown->iDelta == 1) // �����ֵΪ1, ˵�������Spin�����ϵļ�ͷ  
	{
		m_doorNum--;
	}

	if (m_doorNum > 10 || m_doorNum < 1)
	{
		nRes = ValueErrDlg.DoModal();

		m_doorNum = 1;

		if (IDCANCEL == nRes)
		{
			UpdateData(FALSE);
			return;
		}
	}
	UpdateData(false);
	*pResult = 0;
}


void CsbuwayColDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;
	CPortClose portClose;

	set_flag = TRUE;

	if (port_flag == TRUE)
	{
		int doorSta;
		int iResult = 0;
		int iRadioButton;
		unsigned char doorOrder[6];
		unsigned char openFlag = 0xaa;
		unsigned char closeFlag = 0x55;

		iRadioButton = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO2);

		if (iRadioButton == IDC_RADIO1)
			doorSta = 1;
		if (iRadioButton == IDC_RADIO2)
			doorSta = 0;

		CEdit *SysTimeBox = (CEdit*)this->GetDlgItem(IDC_EDIT1);

		switch (m_doorNum)
		{
		case 1:
		{
			doorOrder[0] = 0xde;
			doorOrder[1] = 0xdf;
			doorOrder[2] = 0xef;
			doorOrder[3] = 0xd2;
			doorOrder[4] = 0x20;
			doorOrder[5] = 0x01;
			break;
		}
		case 2:
		{
			doorOrder[0] = 0xde;
			doorOrder[1] = 0xdf;
			doorOrder[2] = 0xef;
			doorOrder[3] = 0xd2;
			doorOrder[4] = 0x20;
			doorOrder[5] = 0x02;
			break;
		}
		case 3:
		{
			doorOrder[0] = 0xde;
			doorOrder[1] = 0xdf;
			doorOrder[2] = 0xef;
			doorOrder[3] = 0xd2;
			doorOrder[4] = 0x20;
			doorOrder[5] = 0x03;
			break;
		}
		case 4:
		{
			doorOrder[0] = 0xde;
			doorOrder[1] = 0xdf;
			doorOrder[2] = 0xef;
			doorOrder[3] = 0xd2;
			doorOrder[4] = 0x20;
			doorOrder[5] = 0x04;
			break;
		}
		case 5:
		{
			doorOrder[0] = 0xde;
			doorOrder[1] = 0xdf;
			doorOrder[2] = 0xef;
			doorOrder[3] = 0xd2;
			doorOrder[4] = 0x20;
			doorOrder[5] = 0x05;
			break;
		}
		case 6:
		{
			doorOrder[0] = 0xde;
			doorOrder[1] = 0xdf;
			doorOrder[2] = 0xef;
			doorOrder[3] = 0xd2;
			doorOrder[4] = 0x20;
			doorOrder[5] = 0x06;
			break;
		}
		case 7:
		{
			doorOrder[0] = 0xde;
			doorOrder[1] = 0xdf;
			doorOrder[2] = 0xef;
			doorOrder[3] = 0xd2;
			doorOrder[4] = 0x20;
			doorOrder[5] = 0x07;
			break;
		}
		case 8:
		{
			doorOrder[0] = 0xde;
			doorOrder[1] = 0xdf;
			doorOrder[2] = 0xef;
			doorOrder[3] = 0xd2;
			doorOrder[4] = 0x20;
			doorOrder[5] = 0x08;
			break;
		}
		case 9:
		{
			doorOrder[0] = 0xde;
			doorOrder[1] = 0xdf;
			doorOrder[2] = 0xef;
			doorOrder[3] = 0xd2;
			doorOrder[4] = 0x20;
			doorOrder[5] = 0x09;
			break;
		}
		case 10:
		{
			doorOrder[0] = 0xde;
			doorOrder[1] = 0xdf;
			doorOrder[2] = 0xef;
			doorOrder[3] = 0xd2;
			doorOrder[4] = 0x20;
			doorOrder[5] = 0x10;
			break;
		}
		}

		iResult = WriteComBuf(doorOrder, 6);

		Sleep(1000);

		if (0 == doorSta)
		{
			iResult = WriteComBuf(&openFlag, 1);
		}
		else
		{
			iResult = WriteComBuf(&closeFlag, 1);
		}

		if (iResult == TRUE)
		{
			nRes = MessageBox(_T("��Ϣ���ͳɹ���"), _T(""), MB_ICONEXCLAMATION | MB_OKCANCEL);

			if (IDCANCEL == nRes)
			{
				UpdateData(FALSE);
				return;
			}
		}
		else
		{
			nRes = MessageBox(_T("��Ϣ����ʧ�ܣ�"), _T(""), MB_ICONEXCLAMATION | MB_OKCANCEL);

			if (IDCANCEL == nRes)
			{
				UpdateData(FALSE);
				return;
			}
		}
	}
	else
	{
		nRes = MessageBox(_T("���ȴ򿪴��ڣ�"), _T(""), MB_ICONEXCLAMATION | MB_OKCANCEL);

		if (IDCANCEL == nRes)
		{
			UpdateData(FALSE);
			return;
		}
	}

	set_flag = FALSE;
}


void CsbuwayColDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	INT_PTR nRes;
	unsigned char i;
	unsigned char doorNum;
	unsigned char doorOrder[6];
	unsigned char openFlag = 0xaa;
	unsigned char closeFlag = 0x55;

	doorOrder[0] = 0xde;
	doorOrder[1] = 0xdf;
	doorOrder[2] = 0xef;
	doorOrder[3] = 0xd2;
	doorOrder[4] = 0x20;

	if (FALSE == port_flag)
	{
		nRes = MessageBox(_T("���ȴ򿪴��ڣ�"), _T(""), MB_ICONEXCLAMATION | MB_OKCANCEL);

		if (IDCANCEL == nRes)
		{
			UpdateData(FALSE);
			return;
		}
	}
	else
	{
		GetDlgItem(IDC_BUTTON5)->SetWindowTextW(_T("һ���ر�"));
		if (FALSE == setAllFlag)
		{
			for (i = 0; i < 6; i++)
			{
				doorOrder[5] = 0x01 + i;
				WriteComBuf(doorOrder, 6);

				Sleep(200);
				WriteComBuf(&closeFlag,2);
			}

			setAllFlag = TRUE;
		}
		else if (TRUE == setAllFlag)
		{
			GetDlgItem(IDC_BUTTON5)->SetWindowTextW(_T("һ����"));
			for (i = 0; i < 6; i++)
			{
				doorOrder[5] = 0x01 + i;
				WriteComBuf(doorOrder, 6);

				Sleep(200);
				WriteComBuf(&openFlag, 2);
			}

			setAllFlag = FALSE;
		}

		nRes = MessageBox(_T("��Ϣ������ϣ�"), _T(""), MB_ICONEXCLAMATION | MB_OKCANCEL);

		if (IDCANCEL == nRes)
		{
			UpdateData(FALSE);
			return;
		}
	}
}
