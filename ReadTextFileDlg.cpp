
// ReadTextFileDlg.cpp : ��@��
//

#include "stdafx.h"
#include "ReadTextFile.h"
#include "ReadTextFileDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include "stdio.h"
#include <string >
#include <fstream>
#include "windows.h"
#include "afxwin.h"
#include "Winuser.h"
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �� App About �ϥ� CAboutDlg ��ܤ��

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ܤ�����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

// �{���X��@
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CReadTextFileDlg ��ܤ��



CReadTextFileDlg::CReadTextFileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CReadTextFileDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReadTextFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CReadTextFileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_GetFilePath, &CReadTextFileDlg::OnBnClickedBtnGetfilepath)
	ON_BN_CLICKED(IDC_BTN_ReadData, &CReadTextFileDlg::OnBnClickedBtnReaddata)
	ON_BN_CLICKED(IDC_BTN_Write, &CReadTextFileDlg::OnBnClickedBtnWrite)
END_MESSAGE_MAP()


// CReadTextFileDlg �T���B�z�`��

BOOL CReadTextFileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �N [����...] �\���[�J�t�Υ\���C

	// IDM_ABOUTBOX �����b�t�ΩR�O�d�򤧤��C
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

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO: �b���[�J�B�~����l�]�w

	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
}

void CReadTextFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CReadTextFileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ø�s���˸m���e

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N�ϥܸm����Τ�ݯx��
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �yø�ϥ�
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ��ϥΪ̩즲�̤p�Ƶ����ɡA
// �t�ΩI�s�o�ӥ\����o�����ܡC
HCURSOR CReadTextFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CReadTextFileDlg::OnBnClickedBtnGetfilepath()
{
	// TODO: �b���[�J����i���B�z�`���{���X

}
void CReadTextFileDlg::OnBnClickedBtnReaddata()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	char  l_sFilePath[20]="D:\\TEST2.txt";//file path
	char  l_cDatabuffer[50]={""};
	char  l_cDatabuffer2[50]={""};
	FILE *fp;//file
	UINT16 l_nError;//save open file return value 
	l_nError = fopen_s(&fp,l_sFilePath,"r+");//Open file ;parameter 1 = file path ,parameter 2 = open type
	fread(l_cDatabuffer,1,  sizeof(l_cDatabuffer), fp); // fread�^��Ū����byte��
	CString l_sDataBuffer(l_cDatabuffer);//convert char to CString 
	SetDlgItemText(IDC_EDIT_FileData,l_sDataBuffer);//show the data to dialog
	fclose(fp);
}
void CReadTextFileDlg::OnBnClickedBtnWrite()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	char  l_sFilePath[20]="D:\\test.txt";//file path
	CString l_CsDataBuffer;
	FILE *fp;//file
	UINT16 l_nError;//save open file return value 
	l_nError = fopen_s(&fp,l_sFilePath,"w+");//Open file ;parameter 1 = file path ,parameter 2 = open type
	GetDlgItemText(IDC_EDIT_WriteData,l_CsDataBuffer);
	fwrite(l_CsDataBuffer,sizeof(l_CsDataBuffer),sizeof(l_CsDataBuffer),fp);
	fclose(fp);
}
