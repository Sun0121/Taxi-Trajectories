#pragma once
const int MAX_POINT = 6000;
template<class T>
class Vector
{
public:
	Vector() { sizeVector = 0; }
	~Vector() {}
	int size() {
		return sizeVector;
	}
	void push_back(T & e) {
		data[sizeVector++] = e;
	}
	T & operator[](int ind) {
		return data[ind];
	}
private:
	int sizeVector;
	T data[MAX_POINT];
};


