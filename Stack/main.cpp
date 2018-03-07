#include "../../public/headfile.hpp"

namespace myStack1 
{
	template<typename T>
	class Stack
	{
	public:
		void push(const T& value);
		void pop();
		T top() const;
		bool empty() const;

	private:
		vector<T> m_vtElems;
	};

	template<typename T>
	void Stack<T>::push(const T& value)
	{
		m_vtElems.push_back(value);
	}

	template<typename T>
	void Stack<T>::pop()
	{
		if (m_vtElems.empty())
		{
			throw std::out_of_range("Stack<>::pop(): empty stack");
		}
		m_vtElems.pop_back();
	}

	template<typename T>
	T Stack<T>::top() const
	{
		if (m_vtElems.empty())
		{
			throw std::out_of_range("Stack<>::pop(): empty stack");
		}
		return m_vtElems.back();
	}

	template<typename T>
	bool Stack<T>::empty() const
	{
		return m_vtElems.empty();
	}


	// 特例化
	template<>
	class Stack<string>
	{
	public:
		void push(const string &szStr)
		{
			elems.push_back(szStr);
		}

		void pop()
		{
			if (elems.empty())
			{
				throw std::out_of_range("Stack<string>::pop(): empty stack");
			}
			elems.pop_back();
		}

		string top() const
		{
			if (elems.empty())
			{
				throw std::out_of_range("Stack<string>::pop(): empty stack");
			}
			return elems.back();
		}

		bool empty() const
		{
			return elems.empty();
		}
	private:
		deque<string> elems;
	};

}

namespace myStack2
{
	// 缺省模板实参
	template<typename T, typename CONT = vector<T>>
	class Stack
	{
	public:
		void push(const T& elem)
		{
			elems.push_back(elem);
		}

		void pop();
		T top() const;

		bool empty() const
		{
			return elems.empty();
		}
	private:
		CONT elems;
	};

	template<typename T, typename CONT>
	void Stack<T, CONT>::pop()
	{
		if (elems.empty())
		{
			throw std::out_of_range("Stack<>::pop(): empty stack");
		}
		elems.pop_back();
	}

	template<typename T, typename CONT>
	T Stack<T, CONT>::top() const
	{
		if (elems.empty())
		{
			throw std::out_of_range("Stack<>::pop(): empty stack");
		}
		return elems.back();
	}
}


void test1()
{
	using namespace myStack1;

	Stack<int> intStack;
	intStack.push(7);
	cout << intStack.top() << endl;

	Stack<string> strStack;
	strStack.push("hello world");
	try
	{
		cout << strStack.top() << endl;
		strStack.pop();
		strStack.pop();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}

void test2()
{
	using namespace myStack2;
	Stack<int> intStack;
	intStack.push(7);
	cout << intStack.top() << endl;

	Stack<string, deque<string>> strStack;
	strStack.push("hello world");
	try
	{
		cout << strStack.top() << endl;
		strStack.pop();
		strStack.pop();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}

int main(int argc, char *argv[])
{
	test2();
	return 0;
}