// Debug-CLRConsole.cpp: ����Ŀ�ļ���

#include "stdafx.h"

using namespace System;
using namespace CLR_link;

int main(array<System::String ^> ^args)
{
	Class1 tmp;
	tmp.roadFromFile();
	cli::array<CMetaData ^> ^ showList = tmp.Traverse(2);
    Console::WriteLine(showList->Length);
    return 0;
}