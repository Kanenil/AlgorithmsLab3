#include "Stack.h"

template<class T>
void Stack<T>::MAKENULL()
{
	if (elements != nullptr)
		delete[]elements;
	elements = nullptr;
}

template<class T>
void Stack<T>::PUSH(T element)
{
	if (elements == nullptr)
		RestoreMemory();
	if (top == add)
		RestoreMemory();
	elements[top] = element;
	top++;
}

template<class T>
T Stack<T>::POP()
{
	T element = top - 1 >= 0 ? elements[top - 1] : NULL;
	if (top - 1 >= 0)
		elements[--top] = NULL;
	return element;
}

template<class T>
T Stack<T>::TOP()
{
	return top - 1 >= 0 ? elements[top - 1] : NULL;
}

template<class T>
bool Stack<T>::EMPTY()
{
	return elements == nullptr || top == 0;
}

template<class T>
void Stack<T>::PRINT()
{
	for (int i = 0; i < top; i++)
		std::cout << elements[i] << ' ';
}

template<class T>
void Stack<T>::RestoreMemory()
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
