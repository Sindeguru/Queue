#pragma once
#include <iostream>
#include "list.h"
using namespace std;
template <class T>

class TQueueList
{
protected:
	TList<T> list;

public:
	TQueueList();
	TQueueList(TQueueList& q);
	~TQueueList();

	T Get(); // = pop

	TQueueList<T>& operator= (TQueueList<T>& _v);

	void Push(T s);

	template<class T1>
	friend ostream& operator<< (ostream& ostr, const TQueueList<T1>& A);
	template<class T1>
	friend istream& operator>> (istream& istr, TQueueList<T1>& A);

	int GetCount();

	bool IsEmpty();
	bool IsFull();
};

template<class T>
TQueueList<T>::TQueueList()
{
}

template<class T>
TQueueList<T>::TQueueList(TQueueList& q)
{
	list = q.list;
}

template<class T>
TQueueList<T>::~TQueueList()
{
}

template<class T>
T TQueueList<T>::Get()
{
	if (list.IsEmpty())
		throw "Queue is empty";
	T tmp = list.GetFirst()->GetData();
	list.DellFirst();
	return tmp;
}

template<class T>
TQueueList<T>& TQueueList<T>::operator=(TQueueList<T>& _v)
{
	if (this == &_v)
		return *this;
	list = _v.list;
	return *this;
}


template<class T>
void TQueueList<T>::Push(T s)
{
	list.InsLast(s);
}

template<class T>
int TQueueList<T>::GetCount()
{
	return list.GetCount();
}

template<class T>
bool TQueueList<T>::IsEmpty()
{
	return list.IsEmpty();
}

template<class T>
bool TQueueList<T>::IsFull()
{
	return list.IsFull();
}

template<class T1>
ostream& operator<<(ostream& ostr, const TQueueList<T1>& A)
{
	return ostr << A.list;
}

template<class T1>
istream& operator>>(istream& istr, TQueueList<T1>& A)
{
	return istr >> A.list;
}
