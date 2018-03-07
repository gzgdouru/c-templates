#include "../../public/headfile.hpp"

template<typename T, int MAXSIZE>
class Stack
{
public:
	Stack();
	void push(const T& elem);
	void pop();
	T top() const;
	
	bool empty()
	{
		return numelems == 0;
	}

	bool full()
	{
		return numelems == MAXSIZE;
	}
private:
	T elems[MAXSIZE];
	int numelems;
};

template<typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack():
	numelems(0)
{

}

template<typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(const T& elem)
{
	elems[numelems++] = elem;
}

template<typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::pop()
{
	if (numelems <= 0)
	{
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	--numelems;
}

template<typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::top() const
{
	if (numelems <= 0)
	{
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	return elems[numelems - 1];
}

int main(int argc, char *argv[])
{	
	try
	{
		int *cint = 0;
		cout << sizeof(int[]) << endl;;
		Stack<int, 20> int20Stack;
		Stack<int, 40> int40Stack;
		Stack<string, 40> str40Stack;

		int20Stack.push(7);
		cout << int20Stack.top() << endl;
		int20Stack.pop();

		str40Stack.push("hello world");
		cout << str40Stack.top() << endl;
		str40Stack.pop();
		str40Stack.pop();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	return 0;
}