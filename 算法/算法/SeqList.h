#pragma once

#include"config.h"
using namespace std;
const int MAXSIZE = 100;
template<class DataType>
class SeqList
{
public:
	SeqList() { length = 0; }
	~SeqList() = default;
	SeqList(DataType a[], int n);
	int Length()const { return this->length; }
	DataType Get(int i)const;
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();
private:
	DataType data[MAXSIZE];
	int length;
};

template<class DataType>
inline SeqList<DataType>::SeqList(DataType a[], int n)
{
	if (n > MAXSIZE) throw "参数非法";
	memcpy(this->data, a, n*sizeof(DataType));
	this->length = n;
}

template<class DataType>
inline DataType SeqList<DataType>::Get(int i) const
{
	if (i<1||i>length)throw "查找位置非法";
	return this->data[i-1];
}

template<class DataType>
inline int SeqList<DataType>::Locate(DataType x)
{
	int i = 0;
	for (i = 0; i < length; ++i)
		if (data[i] == x)
			return ++i;
	return i;
}

template<class DataType>
inline void SeqList<DataType>::Insert(int i, DataType x)
{
	int j = 0;
	if (length >= MAXSIZE)throw "上溢";
	if (i<1 || i>length + 1)throw "下溢";
	for (j = length; j>i; --j)	
		data[j] = data[j - 1];
	data[j - 1] = x;
	length += 1;
}

template<class DataType>
inline DataType SeqList<DataType>::Delete(int i)
{
	if (length == 0)throw "下溢";
	if (i<1 || i>length)throw "位置";
	x = data[i - 1];
	for (int j = i; j < length; ++j)
		data[j - 1] = data[j];
	--length;
	return x;
}

template<class DataType>
inline void SeqList<DataType>::PrintList()
{
	for (int i = 0; i < length; ++i)
		cout << data[i];
}
