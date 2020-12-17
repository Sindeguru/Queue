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
	int counter;

public:
	TQueue(int size = 0);
	TQueue(TQueue& q);
	~TQueue();

	void Push(T s);
	T Pop(); //Вывод последнего элемента и его удаление
	bool IsEmpty();
	bool IsFull();
};

template<class T>
inline TQueue<T>::TQueue(int size)
{
	if (size < 0) throw logic_error("size < 0");
	arr = new T[size];
	this->size = size;
	start = 0;
	finish = 0;
	counter = 0;
}

template<class T>
inline TQueue<T>::TQueue(TQueue& q)
{
	this->size = q.size;
	this->arr = new T * [q.size];
	this->counter = q.counter;
	this->start = q.start;
	this->finish = q.finish;

	if (start > finish)
		for (int i = start; i < finish; i++)
			this->arr[i] = q.arr[i];
	else
		for (int i = finish; i < start; i++)
			this->arr[i] = q.arr[i];
}

template<class T>
inline TQueue<T>::~TQueue()
{
	if (arr != 0) delete[] arr;
	start = 0;
	finish = 0;
	counter = 0;
}

template<class T>
inline void TQueue<T>::Push(T s)
{
	if ((start == finish) && (IsFull())) throw logic_error("Full queue");
	arr[finish] = s;
	finish = (finish + 1) % size;
	counter++;
}

template<class T>
inline T TQueue<T>::Pop()
{
	if (IsEmpty()) throw logic_error("Queue is empty");
	T a = arr[start];
	arr[start] = 0;
	start = (start + 1) % size;
	counter--;
	return a;
}

template<class T>
inline bool TQueue<T>::IsEmpty()
{
	return (counter == 0);
}

template<class T>
inline bool TQueue<T>::IsFull()
{
	return (counter >= size);
}

