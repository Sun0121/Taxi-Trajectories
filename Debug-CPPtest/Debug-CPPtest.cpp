// Debug-CPPtest.cpp: 主项目文件。

#include "stdafx.h"
#include "..\CppGetData\CppGetData.h"

using namespace System;

int main()
{
	Console::WriteLine("start");
	CCppGetData *ptr = new CCppGetData();//为何这里非得new？直接CCppGetData ptr不行
	Console::WriteLine("start");
	ptr->LoadData("F:");
	Console::WriteLine("finish");
    return 0;
}
