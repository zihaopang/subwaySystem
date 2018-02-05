// sbuwayColDlg.cpp : 实现文件

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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CsbuwayColDlg 对话框



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


// CsbuwayColDlg 消息处理程序

BOOL CsbuwayColDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	//设置标题字体  
	m_Font.CreatePointFont(300, _T("华文行楷"), NULL);
	m_static.SetFont(&m_Font, true);
	m_static.SetWindowText(_T("地 铁 门 状 态 信 息 检 测 系 统"));

	//设置编辑框字体
	CEdit *m_EditAa = (CEdit *)GetDlgItem(IDC_EDIT1);
	m_textWin.CreatePointFont(180, _T("宋体"));
	m_EditAa->SetFont(&m_textWin);
	//设置门号编辑框字体
	CEdit *m_EditBa = (CEdit *)GetDlgItem(IDC_EDIT2);
	m_door.CreatePointFont(150, _T("宋体"));
	m_EditBa->SetFont(&m_door);
	//设置RADIO BUTTON字体
	CEdit *m_EditCa = (CEdit *)GetDlgItem(IDC_RADIO1);
	m_radBut1.CreatePointFont(150, _T("宋体"));
	m_EditCa->SetFont(&m_radBut1);
	CEdit *m_EditDa = (CEdit *)GetDlgItem(IDC_RADIO2);
	m_radBut2.CreatePointFont(150, _T("宋体"));
	m_EditDa->SetFont(&m_radBut2);
	//设置按钮字体
	CEdit *m_EditEa = (CEdit *)GetDlgItem(IDC_BUTTON1);
	m_button1.CreatePointFont(150, _T("宋体"));
	m_EditEa->SetFont(&m_button1);
	CEdit *m_EditFa = (CEdit *)GetDlgItem(IDC_BUTTON2);
	m_button2.CreatePointFont(150, _T("宋体"));
	m_EditFa->SetFont(&m_button2);
	CEdit *m_EditGa = (CEdit *)GetDlgItem(IDC_BUTTON3);
	m_button3.CreatePointFont(150, _T("宋体"));
	m_EditGa->SetFont(&m_button3);
	CEdit *m_EditHa = (CEdit *)GetDlgItem(IDC_BUTTON4);
	m_button4.CreatePointFont(150, _T("宋体"));
	m_EditHa->SetFont(&m_button4);
	CEdit *m_EditLa = (CEdit *)GetDlgItem(IDC_BUTTON5);
	m_button5.CreatePointFont(150, _T("宋体"));
	m_EditLa->SetFont(&m_button5);
	//设置group box字体
	CEdit *m_EditIa = (CEdit *)GetDlgItem(IDC_GRP1);
	groupBox1.CreatePointFont(200, _T("隶书"));
	m_EditIa->SetFont(&groupBox1);
	CEdit *m_EditJa = (CEdit *)GetDlgItem(IDC_GRP2);
	groupBox2.CreatePointFont(200, _T("隶书"));
	m_EditJa->SetFont(&groupBox2);

	//设置杂项字体
	m_font1.CreatePointFont(200, _T("宋体"), NULL);
	m_static1.SetFont(&m_doorFont, true);
	m_static1.SetWindowText(_T("串口号:"));

	m_font2.CreatePointFont(200, _T("宋体"), NULL);
	m_static2.SetFont(&m_doorFont, true);
	m_static2.SetWindowText(_T("门号:"));

	m_font3.CreatePointFont(200, _T("宋体"), NULL);
	m_static3.SetFont(&m_doorFont, true);
	m_static3.SetWindowText(_T("门状态:"));

	//设置门状态字体
	CEdit *m_EditKa = (CEdit *)GetDlgItem(DOOR_INFO);
	m_doorInfo.CreatePointFont(200, _T("隶书"));
	m_EditKa->SetFont(&m_doorInfo);

	CheckRadioButton(IDC_RADIO1, //第一个参数为该组的第一个单选按钮的ID   

		IDC_RADIO2, //第二个参数为该组的最后一个单选按钮的ID   

		IDC_RADIO2); //第三个参数为该组中被选中的单选按钮的ID     

	CEdit*  pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit->SetWindowText(_T("1"));

	port_flag = FALSE;

	m_portList.AddString(_T("COM1"));
	m_portList.AddString(_T("COM2"));
	m_portList.AddString(_T("COM3"));
	m_portList.AddString(_T("COM4"));
	// 默认选择第一项
	m_portList.SetCurSel(0);
	SetDlgItemText(IDC_PORT_COMBO, _T("COM1"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CsbuwayColDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CsbuwayColDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CsbuwayColDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;
	int iResult;
	COpenFailDlg OpenFail;
	CPortErrDlg PortErr;

	UpdateData(TRUE); // 将各控件中的数据保存到相应的变量
	
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
		m_showWin.SetWindowText(_T("串口打开成功"));
		port_flag = TRUE;
	}
}

void CsbuwayColDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CloseComPort();
	flag = FALSE;
	m_showWin.SetWindowText(_T("串口已关闭"));
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

		//多行允许
		SysTimeBox->SetSel(-1);
		//打印门信息
		if (numRecord == 0)
		{
			SysTimeBox->SetWindowText(_T(""));
			SysTimeBox->SetWindowText(_T("无数据\n"));
		}
		else
		{
			SysTimeBox->UpdateData(true);
			for (i = 0; i < 10; i++)
			{
				if (doorSta[i] != 0 && doorSta[i] != 0xaa && doorSta[i] != 0x55)
				{
					wsprintf(showBuf, _T("\r\n%d号门"), doorSta[i] >> 4);

					if ((doorSta[i] & 0x0f) == 0x03)
					{
						wsprintf(showBuf, _T("%s:打开\r\n"), showBuf);
					}
					else if ((doorSta[i] & 0x0f) == 0x0c)
					{
						wsprintf(showBuf, _T("%s:关闭\r\n"), showBuf);
					}
					else
					{
						wsprintf(showBuf, _T("%s:状态未知\r\n"), showBuf);
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
	// TODO: 在此添加控件通知处理程序代码
	if (flag)
	{
		flag = FALSE;
		GetDlgItem(IDC_BUTTON3)->SetWindowTextW(_T("开始上报"));
	}
	else
	{
		AfxBeginThread(showCondition, this, THREAD_PRIORITY_IDLE);

		flag = true;
		GetDlgItem(IDC_BUTTON3)->SetWindowTextW(_T("停止上报"));
	}
}

void CsbuwayColDlg::OnCbnSelchangePortCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel;
	// 获取组合框控件的列表框中选中项的索引
	nSel = m_portList.GetCurSel();
	// 根据选中项索引获取该项字符串
	com_port = nSel + 1;
}


void CsbuwayColDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;
	CValueErr ValueErrDlg;

	UpdateData(true);
	if (pNMUpDown->iDelta == -1) // 如果此值为-1 , 说明点击了Spin的往下的箭头  
	{
		m_doorNum++;
	}
	else if (pNMUpDown->iDelta == 1) // 如果此值为1, 说明点击了Spin的往上的箭头  
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
	// TODO: 在此添加控件通知处理程序代码
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
			nRes = MessageBox(_T("信息发送成功！"), _T(""), MB_ICONEXCLAMATION | MB_OKCANCEL);

			if (IDCANCEL == nRes)
			{
				UpdateData(FALSE);
				return;
			}
		}
		else
		{
			nRes = MessageBox(_T("信息发送失败！"), _T(""), MB_ICONEXCLAMATION | MB_OKCANCEL);

			if (IDCANCEL == nRes)
			{
				UpdateData(FALSE);
				return;
			}
		}
	}
	else
	{
		nRes = MessageBox(_T("请先打开串口！"), _T(""), MB_ICONEXCLAMATION | MB_OKCANCEL);

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
	// TODO: 在此添加控件通知处理程序代码

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
		nRes = MessageBox(_T("请先打开串口！"), _T(""), MB_ICONEXCLAMATION | MB_OKCANCEL);

		if (IDCANCEL == nRes)
		{
			UpdateData(FALSE);
			return;
		}
	}
	else
	{
		GetDlgItem(IDC_BUTTON5)->SetWindowTextW(_T("一键关闭"));
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
			GetDlgItem(IDC_BUTTON5)->SetWindowTextW(_T("一键打开"));
			for (i = 0; i < 6; i++)
			{
				doorOrder[5] = 0x01 + i;
				WriteComBuf(doorOrder, 6);

				Sleep(200);
				WriteComBuf(&openFlag, 2);
			}

			setAllFlag = FALSE;
		}

		nRes = MessageBox(_T("信息发送完毕！"), _T(""), MB_ICONEXCLAMATION | MB_OKCANCEL);

		if (IDCANCEL == nRes)
		{
			UpdateData(FALSE);
			return;
		}
	}
}
