// Debug-CLRConsole.cpp: 主项目文件。

#include "stdafx.h"

using namespace System;
using namespace CLR_link;

int main(array<System::String ^> ^args)
{
	Class1 tmp;
	tmp.obtainPath("F:");
	tmp.roadFromFile();
	String ^ str = tmp.carCount(116336,39989,116529,39851,50000,500000);
    Console::WriteLine(str);
    return 0;
}
