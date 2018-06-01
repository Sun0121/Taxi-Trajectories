// Debug-CLRConsole.cpp: 主项目文件。

#include "stdafx.h"

using namespace System;
using namespace CLR_link;

int main(array<System::String ^> ^args)
{
	Class1 tmp;
	tmp.obtainPath("F:\\Document\\Visual Studio 2017\\Projects\\BigProject\\Taxi-Trajectories\\x64\\Release");
	tmp.roadFromFile();
	Console::WriteLine("start");
	String ^ str = tmp.carCount(116336,39989,116529,39851, 56768,600000);
    Console::WriteLine(str);
    return 0;
}
