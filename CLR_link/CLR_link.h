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
			String ^ showList = gcnew String(ptr->traShowMap().c_str());
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
		String ^ relevance(int posa_1_x, int posa_1_y, int posb_1_x, int posb_1_y, int posa_2_x,
			int posa_2_y, int posb_2_x, int posb_2_y, int timeStart, int timeEnd, int interval) {
			String ^ str = gcnew String(ptr->relevance(Coordinate({ posa_1_x ,posa_1_y }), Coordinate({ posb_1_x ,posb_1_y }),
				Coordinate({ posa_2_x ,posa_2_y }), Coordinate({ posb_2_x ,posb_2_y }), timeStart, timeEnd, interval).c_str());
			return str;
		}
		String ^ inOut(int posa_x, int posa_y, int posb_x, int posb_y, int timeStart, int timeEnd, int interval) {
			String ^ str = gcnew String(ptr->inOut(Coordinate({ posa_x ,posa_y }), Coordinate({ posb_x ,posb_y }), 
				timeStart, timeEnd, interval).c_str());
			return str;
		}
	private:
		CCppGetData * ptr;
	};
}
