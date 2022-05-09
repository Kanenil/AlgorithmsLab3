#include "Queue.h"

template<class T>
void Queue<T>::MAKENULL()
{
	if (elements != nullptr)
		delete[]elements;
	elements = nullptr;
}

template<class T>
void Queue<T>::ENQUEUE(T element)
{
	if (elements == nullptr)
		RestoreMemory();
	if (rear == add)
		RestoreMemory();
	elements[rear] = element;
	rear++;
}

template<class T>
T Queue<T>::DEQUEUE()
{
	T element = front != rear ? elements[front] : NULL;
	if (front != rear) {
		DeleteFirstAndRestore();
		rear--;
	}
	return element;
}

template<class T>
T Queue<T>::FRONT()
{
	return !EMPTY() ? elements[front] : NULL;
}

template<class T>
bool Queue<T>::EMPTY()
{
	return elements == nullptr || front == rear;
}

template<class T>
void Queue<T>::PRINT()
{
	for (int i = 0; i < rear; i++)
		std::cout << elements[i] << ' ';
}

template<class T>
void Queue<T>::DeleteFirstAndRestore()
{
	T* tmp = new T[add];
	for (int i = 0, j = 1; j < add; i++, j++)
		tmp[i] = elements[j];
	MAKENULL();
	elements = tmp;
}

template<class T>
void Queue<T>::RestoreMemory()
{
	if (elements == nullptr)
		elements = new T[add];
	else
	{
		T* tmp = new T[add * 2];
		for (int i = 0; i < add; i++)
			tmp[i] = elements[i];
		MAKENULL();
		elements = tmp;
		add *= 2;
	}
}