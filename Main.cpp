#include <iostream>

#include "DynamicArray.h"

int main() {

	DynamicArray<int> arr(10);
	for (int i = 0; i < 10; ++i) {
		arr.append(i);
	}

	std::cout << arr.contains(10) << arr.contains(9) << std::endl;
	
	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr.get(i) << " ";
	}
	std::cout << std::endl;

	return 0;
}