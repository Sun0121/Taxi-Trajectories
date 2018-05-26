// Debug-CLRConsole.cpp: 主项目文件。

#include "stdafx.h"

using namespace System;
using namespace CLR_link;

int main(array<System::String ^> ^args)
{
	Class1 tmp;
	tmp.roadFromFile();
	String ^ str = tmp.Traverse(1, 100);
    Console::WriteLine(str);
    return 0;
}
