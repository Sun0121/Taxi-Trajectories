// CLR_link.h

#pragma once
#include "..\CppGetData\CppGetData.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace System;
using namespace Runtime::InteropServices;

namespace CLR_link {
	public ref class Class1
	{
	public:
		Class1() { ptr = new CCppGetData(); }
		~Class1() { this->!Class1(); }
		!Class1() { delete ptr; }
		int roadFromFile() {
			return ptr->LoadData();
		}
		String ^ Traverse(int start,int end) {
			ptr->showTrack(start,end);
			String ^ showList = gcnew String(ptr->tranShowMap().c_str());
			return showList;
		}
		String ^ carCount(int posa_x,int posa_y,int posb_x,int posb_y, int timeStart, int timeEnd) {
			String ^ str = gcnew String(ptr->carCount(Coordinate({ posa_x,posa_y }), Coordinate({ posb_x,posb_y }), timeStart, timeEnd).c_str());
			return str;
		}
		void obtainPath(String ^ pa) {
			char *path = (char *)(Marshal::StringToHGlobalAnsi(pa)).ToPointer();
			ptr->getPath(path);
		}
		int getCarCountNum() {
			return ptr->carCountNum;
		}
	private:
		CCppGetData * ptr;
	};
}
