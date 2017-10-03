#pragma once
#include"config.h"

template<class DataType>
struct Node {
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class LinkList
{
public:
	LinkList();
	~LinkList();
	LinkList(DataType a[], int n);
	int length();
	DataType Get(int j);
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();
private:
	Node<DataType>* head;
};

template<class DataType>
inline LinkList<DataType>::LinkList(DataType a[], int n)
{
	head = new Node; head->next = NULL;
	for (int i = 0; i < n; ++i)
	{
		Node<DataType>* s = new Node;
		s->data = a[i];
		s->next = head->next; head->next = s;
	}
}

template<class DataType>
inline int LinkList<DataType>::length()
{
	Node<DataType>* p = head->next; int count = 0;
	while (p != NULL)
	{
		p = p->next;
		++count;
	}
	delete p;
	return count;
}

template<class DataType>
inline DataType LinkList<DataType>::Get(int j)
{
	Node<DataType>*p = head->next; int count = 1;
	while (p != NULL)
	{
		p = p->next;
		++count;
	}
	if (p == NULL)throw"Error";
	else return p->data;
}

template<class DataType>
inline int LinkList<DataType>::Locate(DataType x)
{
	Node<DataType>* p = head->next; int count = 1;
	while (p!=NULL)
	{
		if (p->data == x)return count;
		p = p->next;
		++count;
	}
	return 0;
}

template<class DataType>
inline void LinkList<DataType>::Insert(int i, DataType x)
{
	Node<DataType>*p = head; int count = 0;
	while (p != NULL&&count < i - 1)
	{
		p = p->next;
		++count;
	}
	if (p == NULL)throw"Error";
	else {
		Node<DataType>* p = new Node; s->data = x;
		s->next = p->next; p->next = s;
	}
}

template<class DataType>
inline DataType LinkList<DataType>::Delete(int i)
{
	Node<DataType>* p = head; int count = 0;
	while (p!=NULL&&count<i-1)
	{
		p = p->next;
		++count;
	}
	if (p == NULL || p->next == NULL)
		throw"Error";
	else {
		Node<DataType>* q = p->next; int x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}

template<class DataType>
inline void LinkList<DataType>::PrintList()
{
	Node<DataType>* p = head->next;
	while (p!=NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

template<class DataType>
inline LinkList<DataType>::LinkList()
{
	head = new Node;
	head->next = NULL;
}

template<class DataType>
inline LinkList<DataType>::~LinkList()
{
	while (head != NULL)
	{
		Node<DataType>* q = head;
		head = head->next;
		delete q;
	}
}
