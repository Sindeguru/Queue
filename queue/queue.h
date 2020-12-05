#pragma once
#include <iostream>

using namespace std;
template <class T>
class TQueue
{
protected:
	int size;
	T* arr;
	int start;
	int finish;

public:
	TQueue();
	TQueue(int size);
	TQueue(TQueue& q);
	~TQueue();

	void push(T s);
	T pop(); //Вывод последнего элемента и его удаление
	bool empty();

};

template<class T>
inline TQueue<T>::TQueue()
{
	arr = new T * [1];
	start = 0;
	finish = 0;
	size = 1;
	arr[0] = 0;
}

template<class T>
inline TQueue<T>::TQueue(int size)
{
	if (size < 0) throw logic_error("size < 0");
	arr = new T [size];
	this->size = size;
	start = 0;
	finish = 0;
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

template<class T>
inline TQueue<T>::TQueue(TQueue& q)
{
	this->size = q.size;
	this->arr = new T * [q.size];
	for (int i = 0; i < q.size; i++)
		this->arr[i] = q.arr[i];
	this->start = q.start;
	this->finish = q.finish;
}

template<class T>
inline TQueue<T>::~TQueue()
{
	if (arr != 0) delete[] arr;
	start = 0;
	finish = 0;
}

template<class T>
inline void TQueue<T>::push(T s)
{
	if ((start == finish) && (arr[finish] != 0)) throw logic_error("Full queue");
	arr[finish] = s;
	finish = (finish + 1) % size;
}

template<class T>
inline T TQueue<T>::pop()
{
	if ((finish == start) && (arr[start] == 0)) throw logic_error("Queue is empty");
	T a = arr[start];
	arr[start] = 0;
	start = (start + 1) % size;
	return a;
}

template<class T>
inline bool TQueue<T>::empty()
{
	if (start == finish)
		return true;
	else
		return false;
}
