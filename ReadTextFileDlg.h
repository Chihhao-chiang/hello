
// ReadTextFileDlg.h : ���Y��
//

#pragma once


// CReadTextFileDlg ��ܤ��
class CReadTextFileDlg : public CDialogEx
{
// �غc
public:
	CReadTextFileDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_READTEXTFILE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnGetfilepath();
	afx_msg void OnBnClickedBtnReaddata();

	afx_msg void OnBnClickedBtnWrite();
};
