﻿
// Choose10From15Dlg.h: 头文件
//

#pragma once


// CChoose10From15Dlg 对话框
class CChoose10From15Dlg : public CDialogEx
{
// 构造
public:
	CChoose10From15Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHOOSE10FROM15_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult);
	CProgressCtrl m_pro;
	afx_msg void OnBnClickedButton1();
	CStatic m_text;
	CButton m_button1;
	CStatic m_text2;
	afx_msg void OnBnClickedButton2();
};
