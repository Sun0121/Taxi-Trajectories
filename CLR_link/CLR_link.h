// CLR_link.h

#pragma once
#include "..\CppGetData\CppGetData.h"

using namespace System;
using namespace Runtime::InteropServices;

namespace CLR_link {
	public ref class CMetaData
	{
	public:
		int id, year, month, day, hour, minue, sec;
		double longitude, dimension;
		CMetaData() {}
		CMetaData(MetaData &e) {
			id = e.id, year = e.year, month = e.month, day = e.day, hour = e.hour, minue = e.minue, sec = e.sec;
			longitude = e.longitude, dimension = e.dimension;
		}
	};
	public ref class Class1
	{
	public:
		Class1() { ptr = new CCppGetData(); }
		~Class1() { this->!Class1(); }
		!Class1() { delete ptr; }
		int roadFromFile() {
			return ptr->roading();
		}
		cli::array<CMetaData ^> ^  Traverse(int carInd) {
			cli::array<CMetaData ^> ^ showList = gcnew cli::array<CMetaData ^>(ptr->carData[carInd].size());
			int x = ptr->carData[carInd].size();
			for (int i = 0; i < ptr->carData[carInd].size(); i++)
			{
				CMetaData ^ tmp = gcnew CMetaData(ptr->carData[carInd][i]);
				showList[i] = tmp;
			}
			return showList;
		}
		void obtainPath(String ^ pa) {
			char *path = (char *)(Marshal::StringToHGlobalAnsi(pa)).ToPointer();
			ptr->getPath(path);
		}
	private:
		CCppGetData * ptr;
	};
}
