// m_showWin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "sbuwayCol.h"
#include "m_showWin.h"
#include "afxdialogex.h"


// m_showWin �Ի���

IMPLEMENT_DYNAMIC(m_showWin, CDialogEx)

m_showWin::m_showWin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SBUWAYCOL_DIALOG, pParent)
{

}

m_showWin::~m_showWin()
{
}

void m_showWin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(m_showWin, CDialogEx)
	//ON_CBN_SELCHANGE(IDC_PORT_COMBO, &m_showWin::OnCbnSelchangePortCombo)
	ON_STN_CLICKED(DOOR_INFO, &m_showWin::OnStnClickedInfo)
END_MESSAGE_MAP()


// m_showWin ��Ϣ�������

void m_showWin::OnStnClickedInfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
