
// ReadTextFileDlg.cpp : 實作檔
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


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
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


// CReadTextFileDlg 對話方塊



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


// CReadTextFileDlg 訊息處理常式

BOOL CReadTextFileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
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

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
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

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CReadTextFileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CReadTextFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CReadTextFileDlg::OnBnClickedBtnGetfilepath()
{
	// TODO: 在此加入控制項告知處理常式程式碼

}
void CReadTextFileDlg::OnBnClickedBtnReaddata()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	char  l_sFilePath[20]="D:\\TEST2.txt";//file path
	char  l_cDatabuffer[50]={""};
	char  l_cDatabuffer2[50]={""};
	FILE *fp;//file
	UINT16 l_nError;//save open file return value 
	l_nError = fopen_s(&fp,l_sFilePath,"r+");//Open file ;parameter 1 = file path ,parameter 2 = open type
	fread(l_cDatabuffer,1,  sizeof(l_cDatabuffer), fp); // fread回傳讀取的byte數
	CString l_sDataBuffer(l_cDatabuffer);//convert char to CString 
	SetDlgItemText(IDC_EDIT_FileData,l_sDataBuffer);//show the data to dialog
	fclose(fp);
}
void CReadTextFileDlg::OnBnClickedBtnWrite()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	char  l_sFilePath[20]="D:\\test.txt";//file path
	CString l_CsDataBuffer;
	FILE *fp;//file
	UINT16 l_nError;//save open file return value 
	l_nError = fopen_s(&fp,l_sFilePath,"w+");//Open file ;parameter 1 = file path ,parameter 2 = open type
	GetDlgItemText(IDC_EDIT_WriteData,l_CsDataBuffer);
	fwrite(l_CsDataBuffer,sizeof(l_CsDataBuffer),sizeof(l_CsDataBuffer),fp);
	fclose(fp);
}
