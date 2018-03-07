#include "../../public/headfile.hpp"

template<typename T>
class Stack
{
public:
	void push(const T& elem);
	void pop();
	T top() const;
	bool empty() const
	{
		return elems.empty();
	}

	template<typename T2>
	Stack<T>& operator=(const Stack<T2> &other);

private:
	deque<T> elems;
};

template<typename T>
void Stack<T>::push(const T& value)
{
	elems.push_back(value);
}

template<typename T>
void Stack<T>::pop()
{
	if (elems.empty())
	{
		throw std::out_of_range("Stack<>::pop(): empty stack");
	}
	elems.pop_back();
}

template<typename T>
T Stack<T>::top() const
{
	if (elems.empty())
	{
		throw std::out_of_range("Stack<>::pop(): empty stack");
	}
	return elems.back();
}

template<typename T>
template<typename T2>
Stack<T>& Stack<T>::operator=(const Stack<T2> &other)
{
	if ((void*)this == (void*)&other)
	{
		return *this;
	}

	Stack<T2> tmp(other);

	elems.clear();

	while (!tmp.empty())
	{
		elems.push_front(tmp.top());
		tmp.pop();
	}
	return *this;
}

int main(int argc, char *argv[])
{
	Stack<int> intStack;
	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	intStack.push(5);

	Stack<float> floatStack;
	floatStack.push(2.2);
	floatStack.push(3.3);
	floatStack.push(4.4);
	floatStack.push(5.5);
	floatStack.push(6.6);

	intStack = floatStack;
	while (!intStack.empty())
	{
		cout << intStack.top() << endl;
		intStack.pop();
	}

	return 0;
}