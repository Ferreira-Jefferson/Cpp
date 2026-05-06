#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const &val) {
	std::cout << val << std::endl;
}

template <typename T>
void doubleVal(T &val) {
	val *= 2;
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};
	std::size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << "before:" << std::endl;
	::iter(arr, len, print<int>);

	::iter(arr, len, doubleVal<int>);
	
	std::cout << std::endl;
	std::cout << "after doubling:" << std::endl;
	::iter(arr, len, print<int>);

	const std::string strs[] = {"hello", "world", "42"};
	std::size_t slen = sizeof(strs) / sizeof(strs[0]);

	std::cout << std::endl;
	std::cout << "const strings:" << std::endl;
	::iter(strs, slen, print<std::string>);

	return 0;
}
