#pragma once
#include <iostream>

using namespace std;
template <class T>
class TQueue
{
protected:
	int size;
	T** arr;
	int start;
	int finish;

public:
	TQueue();
	TQueue(int size);
	TQueue(TQueue& q);
	~TQueue();

	void push(T& s);
	T pop();

	//int full(); //empty

};

template<class T>
inline TQueue<T>::TQueue()
{

}

template<class T>
inline TQueue<T>::TQueue(int size)
{

}

template<class T>
inline TQueue<T>::TQueue(TQueue& q)
{

}

template<class T>
inline TQueue<T>::~TQueue()
{

}

template<class T>
inline void TQueue<T>::push(T& s)
{

}

template<class T>
inline T TQueue<T>::pop()
{

}