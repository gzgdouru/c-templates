#include "../../public/headfile.hpp"

namespace myproject
{
	template<typename T>
	const T& max(const T& elem1, const T& elem2)
	{
		return elem1 > elem2 ? elem1 : elem2;
	}

	const int& max(const int& elem1, const int& elem2)
	{
		return elem1 > elem2 ? elem1 : elem2;
	}

	template<typename T>
	const T*& max(const T*& elem1, const T*& elem2)
	{
		return *elem1 > *elem2 ? elem1 : elem2;
	}

	template<typename T>
	const T& max(const T& elem1, const T& elem2, const T& elem3)
	{
		return myproject::max(myproject::max(elem1, elem2), elem3);
	}
}

void test1()
{
	int i = 42;
	cout << "max(7, i): " << myproject::max(7, i) << endl;

	double d1 = 3.14;
	double d2 = -6.7;
	cout << "max(d1, d2): " << myproject::max(d1, d2) << endl;

	string s1 = "mathcmatics";
	string s2 = "math";
	cout << "max(s1, s2): " << myproject::max(s1, s2) << endl;
}

void test2()
{
	cout << myproject::max(7, 42, 68) << endl;
	cout << myproject::max(7.0, 42.0) << endl;
	cout << myproject::max('a', 'b') << endl;
	cout << myproject::max(7, 42) << endl;
	cout << myproject::max<>(7, 42) << endl;
	cout << myproject::max<double>(7, 42) << endl;
	cout << myproject::max('a', 42.7) << endl;
}

int main(int argc, char *argv[])
{
	test2();
	return 0;
}