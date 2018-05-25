// Debug-CPPtest.cpp: 主项目文件。

#include "stdafx.h"
#include "..\CppGetData\CppGetData.h"

using namespace System;

int main()
{
	CCppGetData *ptr = new CCppGetData();//为何这里非得new？直接CCppGetData ptr不行
	Console::WriteLine("start");
	ptr->getPath("F:");
	ptr->LoadData();
	Console::WriteLine("finish");
    return 0;
}
