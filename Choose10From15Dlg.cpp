
// Choose10From15Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Choose10From15.h"
#include "Choose10From15Dlg.h"
#include "afxdialogex.h"
#include <string>

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


// CChoose10From15Dlg 对话框



CChoose10From15Dlg::CChoose10From15Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHOOSE10FROM15_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChoose10From15Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_pro);
	DDX_Control(pDX, IDC_text, m_text);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_text2, m_text2);
}

BEGIN_MESSAGE_MAP(CChoose10From15Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CChoose10From15Dlg::OnNMCustomdrawProgress1)
	ON_BN_CLICKED(IDC_BUTTON1, &CChoose10From15Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CChoose10From15Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CChoose10From15Dlg 消息处理程序

BOOL CChoose10From15Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// TODO: 在此添加额外的初始化代码
	m_pro.SetRange(0, 100);
	m_pro.SetStep(10);

	SetWindowText(L"十五选十辅助器");

	GetDlgItem(IDC_PROGRESS1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_text)->ShowWindow(SW_HIDE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChoose10From15Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChoose10From15Dlg::OnPaint()
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
HCURSOR CChoose10From15Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChoose10From15Dlg::OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

int a[20];
void CChoose10From15Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_PROGRESS1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_text)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
	m_text2.SetWindowText(L"");
	memset(a, 0, sizeof a);

	srand(time(0));
	m_text.SetWindowTextW(L"0%");
	m_pro.SetPos(0);

	for (int i = 1; i <= 10; i++)
	{
		m_pro.StepIt();
		Sleep(rand() % 1000 + 100);
		std::string pos = std::to_string(m_pro.GetPos())+"%";
		CString text(pos.c_str());
		m_text.SetWindowTextW(text);

		CString ans;
		m_text2.GetWindowText(ans);
		
		int index = rand() % 15;
		while (a[index])
			index = rand() % 15;
		a[index] = 1;
		ans += (char)(index + 'A');
		ans += " ";
		m_text2.SetWindowText(ans);
	}

	GetDlgItem(IDC_PROGRESS1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_text)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
}


void CChoose10From15Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"1.十五选十只有5分，对于水平一般的同学不值得，点击“开始”，相信程序！\n2.开始后请等待结果出现，此时操作容易造成卡顿。", L"使用说明");
}
