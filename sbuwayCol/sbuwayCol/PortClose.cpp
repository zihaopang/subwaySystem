// PortClose.cpp : 实现文件
//

#include "stdafx.h"
#include "sbuwayCol.h"
#include "PortClose.h"
#include "afxdialogex.h"


// CPortClose 对话框

IMPLEMENT_DYNAMIC(CPortClose, CDialogEx)

CPortClose::CPortClose(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CPortClose::~CPortClose()
{
}

void CPortClose::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPortClose, CDialogEx)
END_MESSAGE_MAP()


// CPortClose 消息处理程序
