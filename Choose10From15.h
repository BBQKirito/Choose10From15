
// Choose10From15.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CChoose10From15App:
// 有关此类的实现，请参阅 Choose10From15.cpp
//

class CChoose10From15App : public CWinApp
{
public:
	CChoose10From15App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CChoose10From15App theApp;
